# 🚨 ESP32 Smart Motion Alert System (IoT)

A professional IoT security solution built with **ESP32** and **Telegram Bot API**. This system detects motion using a PIR sensor and sends real-time alerts to a mobile device, featuring a physical arming mechanism and smart delay logic.

## ✨ Key Features
* **Physical Arm/Disarm:** Toggle the system state using a physical push button.
* **Exit Grace Period:** 5-second delay after arming to allow the user to leave the room.
* **Telegram Integration:** Instant notifications via encrypted HTTPS requests.
* **Anti-Spam Logic:** Implements a 1-minute (60s) cooldown between alerts to prevent notification flooding.
* **Non-Blocking Code:** Uses `millis()` instead of `delay()` to ensure the button remains responsive at all times.

## 🛠 Hardware Components
Based on the **ESP32 Basic Starter Kit**:
* **Microcontroller:** ESP32 Development Board.
* **Sensor:** HC-SR501 PIR Motion Sensor.
* **Input:** Tactile Push Button.
* **Wires:** Jumper wires (F-M / F-F).

## 🔌 Wiring Diagram
| Component | Pin | ESP32 Pin |
| :--- | :--- | :--- |
| **PIR Sensor** | VCC | VIN (5V) |
| **PIR Sensor** | GND | GND |
| **PIR Sensor** | OUT | GPIO 13 |
| **Button** | Terminal A | GND |
| **Button** | Terminal B | GPIO 4 |

## 🚀 Setup Instructions
1. Clone this repository.
2. Open the `.ino` file in Arduino IDE.
3. Update your WiFi credentials and Telegram Bot Token/Chat ID.
4. Flash the code to your ESP32.
5. Open Serial Monitor (115200 baud) to verify connectivity.

---
*Developed as part of an Electrical Engineering project.*
