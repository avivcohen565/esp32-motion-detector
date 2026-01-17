# ESP32 Motion Detector – Real-Time Motion Start

Embedded project based on ESP32 for detecting the start of motion in real time.

The project is built step-by-step, fully documented, and versioned with Git and GitHub.

---

## Project Goals
- Read motion sensor data at a fixed rate (real-time loop)
- Apply basic noise filtering
- Detect motion start (one-shot event)
- Output:
  - Serial message (MOTION_START)
  - LED indication on ESP32
- Clean Git history with logical commits

---

## Project Structure
esp32-motion-detector/
├─ README.md
├─ .gitignore
├─ projects/
│  ├─ 01_blink/
│  │  └─ 01_blink.ino
│  └─ 02_motion_mpu6050/
│     └─ 02_motion_mpu6050.ino
└─ docs/
   └─ wiring.md

---

## Hardware
- ESP32 Dev Board
- MPU6050 (GY-521)
- Breadboard and jumper wires

---

## Software
- macOS
- Arduino IDE
- ESP32 board package by Espressif
- Git and GitHub

---

## Author
Aviv Cohen
