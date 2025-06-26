# 💧 Smart Water Level Monitoring System

A real-time smart water monitoring system that combines **IoT hardware**, **Edge AI**, and **Cloud-based visualization** to manage and optimize water usage using the ESP32 microcontroller, ultrasonic sensor, and TensorFlow Lite model.

---

## 📌 Project Overview

This project aims to build an **intelligent water tank monitoring system** that:
- Detects water level using ultrasonic sensors
- Activates a motor (pump) via a relay at low levels
- Sends alerts through a buzzer and OLED display
- Predicts water usage patterns using an ML model trained on real usage data
- Logs data to **InfluxDB** and visualizes it with **Grafana**

---

## 🧠 Features

- 🌊 Real-time water level detection
- 🤖 On-device AI using TensorFlow Lite Micro (Edge ML)
- ⚠️ Auto-alerts via buzzer and display
- 🔁 Automatic motor control using relay
- 📊 Data logging via Wi-Fi to InfluxDB
- 📈 Grafana-based visualization dashboard

---

## 🔌 Hardware Components

- **ESP32-C3 / ESP32-S3**
- **HC-SR04 Ultrasonic Sensor**
- **OLED SSD1306 Display**
- **Buzzer**
- **Relay Module**
- **Water Pump**
- **Button & LED (status controls)**

---

## 🧪 ML Integration

- `train_model_with_noise.py`: Trains a water usage classifier using noisy sensor data
- Model converted to `.tflite`, then `.h` (via `convert_to_header.py`) for ESP32 inference
- `model_data.h`: Embedded model for on-device predictions

---

## 🛠️ Software Stack

| Layer     | Tools/Tech                    |
|-----------|-------------------------------|
| Hardware  | ESP32, HC-SR04, OLED, Relay   |
| Firmware  | Arduino `.ino` sketch         |
| ML Model  | TensorFlow Lite for Micro     |
| Logging   | InfluxDB, HTTPClient          |
| Display   | OLED via Adafruit GFX         |
| Dashboard | Grafana                       |

---


---

## 🔄 Data Flow

1. **Sensor detects level** →  
2. **ESP32 infers usage pattern** →  
3. **Buzzer/display alerts if critical** →  
4. **Motor auto-activates if required** →  
5. **Data logged to InfluxDB via WiFi** →  
6. **Grafana visualizes historical data**

---

## 🚀 Getting Started

1. Flash `Water_Level.ino` to your ESP32
2. Connect hardware as per pin configuration
3. Deploy InfluxDB + Grafana for monitoring
4. (Optional) Retrain ML model using provided scripts

---

## 📸 Demo

🎥 `Water_Monitoring_System_Video.mp4` – Watch a short demonstration of the working prototype.

---

## 📌 Future Improvements

- Add remote control via mobile/web app
- Integrate Firebase or Blynk for real-time app alerts
- Add water quality sensors
- Solar-powered deployment
- Schedule-based ML predictions

---

