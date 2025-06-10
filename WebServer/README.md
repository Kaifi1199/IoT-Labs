# 🔌 Websocket.py

### **Title:** ESP32 WebSocket-Controlled IoT Dashboard with OLED, NeoPixel & DHT Sensor
---
### **Objective**

To build a full-featured web server hosted on an ESP32 microcontroller, enabling real-time control and monitoring of an RGB LED, DHT11 sensor, and OLED display via a stylized dashboard.

---

### **Features**

* 🌡️ Displays live temperature and humidity data from a DHT11 sensor.
* 🌈 Allows RGB LED control via preset or custom values.
* 🖥️ Sends text input to the OLED display.
* 🌐 Combines Station & Access Point mode to support local and external clients.
* 🎨 Includes a beautiful, responsive front-end web interface.

---

### **Technologies Used**

* **Microcontroller**: ESP32
* **Sensor**: DHT11 (Temperature and Humidity)
* **Display**: SSD1306 OLED
* **Lighting**: NeoPixel RGB LED
* **Protocols**: HTTP (Socket), Web server
* **Language**: MicroPython

---

### **How to Run**

1. Flash this script to your ESP32 running MicroPython.
2. Connect to Wi-Fi; ESP32 also creates its own AP.
3. Access the IP shown in Serial Monitor via browser.
4. Use the interface to:

   * Control LED colors.
   * Send text to OLED.
   * View sensor data updating every 2 seconds.

---

### **Learning Outcomes**

* Hosting web servers directly from microcontrollers.
* Real-time UI interaction with embedded hardware.
* Parsing HTTP GET and POST requests manually.
* Building multi-functional dashboards for IoT.

---

### **Applications**

* Smart home dashboards.
* IoT learning platforms.
* Rapid prototyping of sensor + control interfaces.

---

# 🟦 MorseCode\_WebServer.py

### **Title:** MorseGlow: Real-Time Morse Code Transmitter via ESP32 Web Server
---
### **Objective**

To build a creative web-based platform that translates text input into Morse code, visualized through RGB LED blinking patterns and OLED display on an ESP32.

---

### **Features**

* 🔠 Converts input text to Morse code using a predefined dictionary.
* ✴️ Blinks Morse signals using a NeoPixel: red for dots, blue for dashes.
* 🖥️ Displays input text and Morse code on an OLED.
* 🌐 Stylish web interface with form input and responsive layout.
* 💡 Keeps track of and displays the last transmitted Morse sequence.

---

### **Technologies Used**

* **Microcontroller**: ESP32
* **Display**: SSD1306 OLED
* **Lighting**: NeoPixel RGB LED
* **Protocol**: HTTP (Socket), Web Server
* **Language**: MicroPython

---

### **How to Run**

1. Upload this script to your ESP32 running MicroPython.
2. ESP32 will connect to Wi-Fi and serve a web page.
3. Open browser to ESP32 IP and submit a message.
4. The message will:

   * Blink the NeoPixel according to Morse rules.
   * Display the text and Morse code on OLED.

---

### **Learning Outcomes**

* Understand Morse code translation via Python.
* Integrate LEDs and OLED for multi-modal feedback.
* Use HTML forms to trigger hardware-level responses.
* Apply design thinking to build creative embedded UI.

---

### **Applications**

* Educational tools for learning Morse code.
* Creative messaging or alert systems.
* IoT interfaces for expressive microcontroller use.

---
