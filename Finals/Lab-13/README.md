# Lab 13: Environmental Data Classification Using DHT Sensor and Machine Learning

## Objective

This lab demonstrates a complete **end-to-end IoT + Machine Learning pipeline**. Environmental data collected from a DHT sensor is classified using a trained ML model, with deployment support for microcontroller integration and cloud logging (InfluxDB).

## Files Included

### 📁 Machine Learning (Python)

* `0-train_model.py` – Trains a base ML model on clean DHT data.
* `1-dht_data_only.py` – Captures real-time DHT sensor data.
* `2-train_model_with_noise.py` – Trains the model on noisy DHT data to improve generalization.
* `3-classify_2_influx_.py` – Classifies DHT data and sends labeled output to InfluxDB.
* `dht_classifier.h5` – Trained Keras model (saved format).
* `normalization.npz` – Preprocessing parameters (mean/std) used for input normalization.

### 📁 Microcontroller Code

* `esp_2_mos_simple/esp_2_mos_simple.ino` – Arduino sketch to interface ESP device with Mosquitto MQTT broker.

## Purpose of the Lab

* Build and train an ML model to classify environmental conditions using DHT sensor data.
* Simulate real-world deployment by integrating ESP and MQTT with ML inference output.
* Log classified results to a cloud database (InfluxDB) for visualization and analysis.

## Technologies Used

* **Sensors**: DHT11 / DHT22
* **Microcontroller**: ESP8266 / ESP32
* **Language**: Python, C++ (Arduino)
* **Libraries**:

  * `TensorFlow / Keras`
  * `NumPy`, `InfluxDB`, `paho-mqtt`
* **Cloud**: InfluxDB, Mosquitto MQTT
* **IDE**: Arduino IDE, VS Code

## How to Run

### Model Training

```bash
python 0-train_model.py
python 2-train_model_with_noise.py
```

### Real-Time Classification and Logging

```bash
python 3-classify_2_influx_.py
```

### Microcontroller

1. Open `esp_2_mos_simple.ino` in Arduino IDE.
2. Flash it to your ESP board.
3. Make sure Mosquitto broker is running.

## Learning Outcomes

* Understand how to preprocess sensor data and apply ML classification.
* Train and test models with clean vs. noisy data.
* Deploy an end-to-end ML + IoT application with real-time inference and logging.

## Applications

* Smart home/environment monitoring systems.
* Edge-based environmental classification.
* Real-time data analytics for sensor networks.

## Author

This lab forms a part of an advanced IoT + ML curriculum focused on sensor data processing, model training, and deployment.

---
