#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h>
#include <time.h>

// WiFi Credentials
const char* ssid = "NTU FSD";
const char* password = "";

// Firebase Configuration
const String FIREBASE_HOST = "fir-project-1-52110-default-rtdb.firebaseio.com";
const String FIREBASE_AUTH = "vlXrrrTT96X784Tyj11uOVa23DXAhonmdOX7cs3m";

// Firebase path (do NOT include .json, REST API adds it)
const String FIREBASE_PATH = "/sensor_data";

// DHT Sensor
#define DHTPIN 4
#define DHTTYPE DHT11

// Timing
const unsigned long SEND_INTERVAL = 10000;  // 10 seconds
const unsigned long SENSOR_DELAY = 2000;    // 2 seconds

// Global objects
DHT dht(DHTPIN, DHTTYPE);
unsigned long lastSendTime = 0;
unsigned long lastReadTime = 0;

// ====== Setup ======
void setup() {
  Serial.begin(115200);
  Serial.println("\nESP32-S3 DHT11 Firebase Monitor");

  dht.begin();
  connectWiFi();
  initNTP();
}

// ====== Main Loop ======
void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    connectWiFi();
  }

  if (millis() - lastReadTime >= SENSOR_DELAY) {
    float temp, hum;
    if (readDHT(&temp, &hum)) {
      if (millis() - lastSendTime >= SEND_INTERVAL) {
        sendToFirebase(temp, hum);
        lastSendTime = millis();
      }
    }
    lastReadTime = millis();
  }
}

// ====== DHT Functions ======
bool readDHT(float* temp, float* humidity) {
  *temp = dht.readTemperature();
  *humidity = dht.readHumidity();

  if (isnan(*temp) || isnan(*humidity)) {
    Serial.println("DHT read failed!");
    return false;
  }

  Serial.printf("Read: %.1f°C, %.1f%%\n", *temp, *humidity);
  return true;
}

// ====== WiFi Functions ======
void connectWiFi() {
  Serial.print("Connecting to WiFi");
  WiFi.disconnect(true);
  WiFi.begin(ssid, password);

  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 20) {
    delay(500);
    Serial.print(".");
    attempts++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWiFi Connected!");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\nWiFi Failed!");
  }
}

// ====== NTP Functions ======
void initNTP() {
  configTime(5 * 3600, 0, "pool.ntp.org", "time.nist.gov");  // +5 hours for Pakistan
  Serial.println("Waiting for NTP time sync...");
  struct tm timeinfo;
  while (!getLocalTime(&timeinfo)) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("\nTime synced!");
}

// ====== Firebase Functions ======
void sendToFirebase(float temp, float humidity) {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi not connected, skipping Firebase send.");
    return;
  }

  // Get real timestamp
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("Failed to get time, using millis as fallback.");
  }

  char timeStr[30];
  strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", &timeinfo);

  String url = "https://" + FIREBASE_HOST + FIREBASE_PATH + ".json?auth=" + FIREBASE_AUTH;

  // Create JSON payload
  String jsonPayload = "{";
  jsonPayload += "\"temperature\":" + String(temp) + ",";
  jsonPayload += "\"humidity\":" + String(humidity) + ",";
  jsonPayload += "\"timestamp\":\"" + String(timeStr) + "\"";
  jsonPayload += "}";

  Serial.println("Sending to Firebase...");
  Serial.println(jsonPayload);

  HTTPClient http;
  http.begin(url);
  http.addHeader("Content-Type", "application/json");
  int httpCode = http.POST(jsonPayload);

  if (httpCode > 0) {
    String response = http.getString();
    Serial.printf("Firebase response (%d): %s\n", httpCode, response.c_str());
  } else {
    Serial.printf("Firebase POST failed, error: %s\n", http.errorToString(httpCode).c_str());
  }

  http.end();
}
