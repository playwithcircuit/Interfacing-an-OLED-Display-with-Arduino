# 📺 Interfacing OLED Display with Arduino (SSD1306)

A complete beginner-to-intermediate guide to using an OLED display with Arduino. This project demonstrates how to display text, shapes, and graphics using both **I2C** and **SPI** communication interfaces.

---

## 🚀 Overview

OLED (Organic Light Emitting Diode) displays are a powerful upgrade over traditional LCDs. Unlike LCDs, OLED pixels emit their own light, resulting in:

* High contrast and sharp visuals
* No backlight requirement
* Lower power consumption
* Wide viewing angles

In this project, we interface a **0.96-inch 128×64 OLED display (SSD1306)** with Arduino and explore how to control it using libraries.

---

## 🧠 How It Works

The OLED module is driven by the **SSD1306 controller**, which contains internal memory.

* The Arduino sends pixel data to this memory
* The display refreshes itself automatically
* Each bit represents a pixel (ON/OFF)

📌 Memory Structure:

* 8 Pages
* 128 Columns per page
* Each column = 8 vertical pixels

This allows efficient rendering of text, shapes, and images.

---

## 🧰 Components Required

| No. | Component Name         | Quantity | 
| --- | ---------------------- | -------- | 
| 1   | Arduino Nano           | 1        |           
| 2   | OLED Display (SSD1306) | 1        | 
| 3   | Jumper Wires           | Several  | 
| 4   | Breadboard             | 1        | 
| 5   | USB Cable              | 1        | 

---

## 🔌 Pinout Details

### 📍 I2C OLED Pinout

| Pin | Description     |
| --- | --------------- |
| GND | Ground          |
| VCC | Power (3.3V–5V) |
| SCL | Clock Line      |
| SDA | Data Line       |

---

### 📍 SPI OLED Pinout

| Pin  | Description            |
| ---- | ---------------------- |
| GND  | Ground                 |
| VCC  | Power Supply           |
| SCK  | Clock Signal           |
| MOSI | Data Input             |
| CS   | Chip Select            |
| DC   | Data/Command Selection |

---

## 🔗 Wiring Connections

### ✅ I2C Connection

![I2C OLED Display Wiring](https://playwithcircuit.com/wp-content/uploads/2026/04/Wiring-I2C-OLED-Display-with-Arduino-Nano.webp)

| OLED Pin | Arduino UNO/Nano |
| -------- | ---------------- |
| VCC      | 5V               |
| GND      | GND              |
| SCL      | A5               |
| SDA      | A4               |

✔ Uses only 4 wires
✔ Simple and clean setup

---

### ⚡ SPI Connection (Faster Communication)

![SPI OLED Display Wiring](https://playwithcircuit.com/wp-content/uploads/2026/04/Wiring-SPI-OLED-Display-with-Arduino-Nano.webp)

| OLED Pin | Arduino Pin |
| -------- | ----------- |
| VCC      | 5V          |
| GND      | GND         |
| SCK      | D10         |
| MOSI     | D9          |
| CS       | D12         |
| DC       | D11         |

✔ Faster updates
✔ Suitable for animations and graphics

---

## 📚 Required Libraries

Install the following libraries via Arduino IDE:

* **Adafruit SSD1306**
* **Adafruit GFX**

---

## 💡 What You Can Do with OLED

Once connected, you can:

* Display text and sensor values
* Draw shapes (lines, rectangles, circles)
* Show icons and bitmaps
* Create simple UI dashboards

---

## 🛠️ Applications

* IoT Displays
* Sensor Monitoring Systems
* Wearable Devices
* Embedded UI Interfaces
* Portable Electronics

---

## 🧪 Future Improvements

* Add real-time sensor data visualization
* Display graphs and animations
* Integrate with IoT platforms
* Build a menu-driven interface

---

## 🔗 Full Tutorial & Code

For complete step-by-step instructions, detailed explanations, and example code:
👉 https://playwithcircuit.com/interfacing-oled-display-with-arduino/

---

## 🤝 Contributing

Feel free to fork this repository and enhance it with:

* More examples
* Better UI designs
* Additional display modules

---

## 📜 License

This project is open-source and free to use for educational and personal projects.

---

⭐ If you found this helpful, consider starring the repository!
