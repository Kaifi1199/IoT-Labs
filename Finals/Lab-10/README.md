# Lab 10: Introduction to MQTT Protocol Using Python

## Objective

This lab introduces the fundamentals of the **MQTT (Message Queuing Telemetry Transport)** protocol — a lightweight messaging protocol ideal for IoT communication. Using Python and the `paho-mqtt` library, students will explore publishing and subscribing to MQTT topics through structured tasks.

## Files Included

* `Task-1-MQTT.py` – Initializes and sets up MQTT client connections.
* `Task-2-MQTT-SUB.py` – Demonstrates how to subscribe to a topic and receive messages.
* `Task-3-MQTT-PUB.py` – Demonstrates how to publish messages to an MQTT topic.

## Purpose of the Lab

* Understand the client-broker-publisher/subscriber architecture of MQTT.
* Learn to implement MQTT communication using Python.
* Develop practical skills for real-world IoT applications where devices communicate over topics.

## Technologies Used

* **Language**: Python 3.x
* **Library**: `paho-mqtt`
* **MQTT Broker**: Mosquitto (local or public broker like `test.mosquitto.org`)
* **Tools**: Any Python IDE or terminal with pip access

## How to Run

1. Install the `paho-mqtt` library (if not already installed):

```bash
pip install paho-mqtt
```

2. Run the subscriber script in one terminal window:

```bash
python Task-2-MQTT-SUB.py
```

3. Run the publisher script in another terminal window:

```bash
python Task-3-MQTT-PUB.py
```

4. Observe message transmission via the MQTT broker.

## Learning Outcomes

* Set up an MQTT client in Python.
* Publish and subscribe to topics.
* Handle MQTT message callbacks.
* Understand QoS (Quality of Service) levels and topic hierarchy (if implemented).

## Applications

* Smart home automation systems.
* Real-time sensor data communication.
* IoT projects requiring low-bandwidth messaging.

## Author

This lab is part of an academic curriculum to teach IoT communication protocols using Python.

---
