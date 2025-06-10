#include <Arduino.h>
#include <DHT.h>
#include <WiFi.h>
#include <esp_heap_caps.h>

#include "tensorflow/lite/micro/micro_interpreter.h"
#include "tensorflow/lite/micro/micro_mutable_op_resolver.h"
#include "tensorflow/lite/schema/schema_generated.h"
#include "tensorflow/lite/micro/micro_log.h"
#include "model_data.h"

#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

constexpr int kTensorArenaSize = 40 * 1024;
uint8_t* tensor_arena;

const tflite::Model* model = nullptr;
tflite::MicroInterpreter* interpreter = nullptr;
static tflite::MicroMutableOpResolver<3> resolver;

void setup() {
    Serial.begin(115200);
    dht.begin();

    if (!psramInit()) {
        Serial.println("PSRAM init failed!");
        while (1);
    }

    tensor_arena = (uint8_t*)ps_malloc(kTensorArenaSize);
    if (!tensor_arena) {
        Serial.println("Failed to allocate tensor arena!");
        while (1);
    }

    model = tflite::GetModel(dht_classifier_tflite);
    if (model->version() != TFLITE_SCHEMA_VERSION) {
        Serial.println("Model schema mismatch!");
        while (1);
    }

    resolver.AddFullyConnected();
    resolver.AddRelu();
    resolver.AddSoftmax();

    static tflite::MicroInterpreter static_interpreter(model, resolver, tensor_arena, kTensorArenaSize);
    interpreter = &static_interpreter;

    if (interpreter->AllocateTensors() != kTfLiteOk) {
        Serial.println("Tensor allocation failed!");
        while (1);
    }

    Serial.println("Setup complete. Starting inference...");
}

void loop() {
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    if (isnan(temperature) || isnan(humidity)) {
        Serial.println("DHT read failed");
        delay(2000);
        return;
    }

    // Directly use raw values (no normalization)
    TfLiteTensor* input = interpreter->input(0);
    input->data.f[0] = temperature;
    input->data.f[1] = humidity;

    if (interpreter->Invoke() != kTfLiteOk) {
        Serial.println("Inference failed");
        return;
    }

    TfLiteTensor* output = interpreter->output(0);
    int predicted_class = 0;
    float max_prob = output->data.f[0];
    for (int i = 1; i < 5; i++) {
        if (output->data.f[i] > max_prob) {
            max_prob = output->data.f[i];
            predicted_class = i;
        }
    }

    const char* labels[] = {"Normal", "HotHumid", "ColdDry", "HotDry", "ColdHumid"};

    Serial.print("Temp: ");
    Serial.print(temperature);
    Serial.print(" °C, Humidity: ");
    Serial.print(humidity);
    Serial.print(" %, Prediction: ");
    Serial.print(labels[predicted_class]);
    Serial.print(" (");
    Serial.print(max_prob, 4);
    Serial.println(")");

    delay(5000);
}