# Lab 11: IoT Data Logging to Firebase using Arduino

## Objective

This lab demonstrates how to send **temperature and humidity sensor data** from an Arduino-compatible microcontroller (such as NodeMCU or ESP32) to **Firebase Realtime Database**. It includes two variants: one with timestamped logging and one without timestamps.

## Files Included

* `firebase__Temp__Humidity_/firebase__Temp__Humidity_.ino`
  Sends sensor data to Firebase with timestamp support.

* `firebase__Temp__Humidity__without__time/firebase__Temp__Humidity__without__time.ino`
  Sends sensor data to Firebase without timestamp integration.

## Purpose of the Lab

* Learn how to connect an Arduino-based device to Firebase.
* Understand how to structure and send JSON-formatted data.
* Explore the difference between logging with and without timestamps.
* Gain experience in real-time cloud storage for IoT systems.

## Technologies Used

* **Microcontroller**: ESP8266 / ESP32
* **Sensors**: DHT11 / DHT22
* **Platform**: Arduino IDE
* **Cloud**: Firebase Realtime Database
* **Libraries**:

  * `FirebaseESP8266.h` or `FirebaseESP32.h`
  * `DHT.h`

## How to Run

1. Open the `.ino` file in Arduino IDE.
2. Install required libraries via Library Manager.
3. Set your **Firebase host** and **authentication key** in the sketch.
4. Connect your ESP board and upload the code.
5. Open the Serial Monitor to confirm successful data push.

## Firebase Setup

* Create a Firebase project via [Firebase Console](https://console.firebase.google.com/).
* Navigate to Realtime Database > Create Database.
* Enable **read/write access** for initial testing (adjust security rules later).
* Copy the database URL and secret key into the sketch.

## Learning Outcomes

* Send live data to a cloud database.
* Configure Arduino to interact with Firebase APIs.
* Understand how to create structured data entries in a NoSQL database.

## Applications

* Smart agriculture (temperature/humidity logging).
* Environmental monitoring systems.
* Real-time IoT dashboards using Firebase data.

## Author

This lab is part of an academic IoT curriculum for learning cloud-based data logging.

---
