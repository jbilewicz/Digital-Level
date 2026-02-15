# 📐 Digital Level (Poziomica Cyfrowa)

## 📝 Project Overview
This project is a high-precision digital level based on the **ESP32** microcontroller. [cite_start]It utilizes the **MPU6050** 6-axis accelerometer and gyroscope to measure tilt angles in real-time[cite: 13]. [cite_start]When the device reaches a perfectly horizontal position (tilt < 0.30 m/s² on X and Y axes), it triggers an audible alert[cite: 14, 160, 199].

[cite_start]Developed for the **Microprocessor and Embedded Systems** course at **Silesian University of Technology**[cite: 3, 11].

## 💻 Tech Stack
<p align="left">
  <img src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" />
  <img src="https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white" />
  <img src="https://img.shields.io/badge/ESP32-E67E22?style=for-the-badge&logo=espressif&logoColor=white" />
</p>

---

## 🛠️ Components
- [cite_start]**Microcontroller:** ESP32 DEVKIT V1[cite: 220].
- [cite_start]**Sensor:** MPU6050 (Accelerometer & Gyroscope)[cite: 222].
- [cite_start]**Display:** 0.96" SSD1306 OLED (128x64) via I2C[cite: 224].
- [cite_start]**Audio:** Active Buzzer for level notification[cite: 227].
- [cite_start]**Prototyping:** Universal Protoboard (THT)[cite: 230].

---

## 📐 Hardware Design & Pinout
[cite_start]The system is powered via USB (5V)[cite: 14, 135]. [cite_start]Both the sensor and the display share the **I2C bus** (GPIO 21 and 22)[cite: 166].

| Component | ESP32 Pin | Function |
| :--- | :--- | :--- |
| **MPU6050 SDA** | GPIO 21 | [cite_start]I2C Data [cite: 166] |
| **MPU6050 SCL** | GPIO 22 | [cite_start]I2C Clock [cite: 166] |
| **SSD1306 SDA** | GPIO 21 | [cite_start]I2C Data [cite: 166] |
| **SSD1306 SCL** | GPIO 22 | [cite_start]I2C Clock [cite: 166] |
| **Active Buzzer**| GPIO 13 | [cite_start]Level Alert (Inverted Logic) [cite: 156, 206] |



---

## 🚀 Key Algorithms
1. **Level Detection:** The system monitors `acceleration.x` and `acceleration.y`. [cite_start]If both values fall below `LEVEL_THRESHOLD` (0.30), the device is considered level[cite: 160, 199].
2. [cite_start]**Visual Feedback:** Large text (Size 3) displays X/Y acceleration values, and an "**>>OK<<**" message appears when level[cite: 185, 205].
3. [cite_start]**Inverted Buzzer Logic:** The buzzer is activated by pulling the pin **LOW**.

---

## 📂 Repository Structure
- `/Code` - Arduino/C++ source code (.ino).
- [cite_start]`/Docs` - Full technical report in PDF format[cite: 4].
- [cite_start]`/Images` - Photos of the soldered protoboard.

---

<h3 align="left">📫 Reach me:</h3>
<p align="left">
<a href="https://instagram.com/abuk55s" target="blank"><img align="center" src="https://img.shields.io/badge/Instagram-%23E4405F.svg?style=for-the-badge&logo=Instagram&logoColor=white" alt="abuk55s" /></a>
</p>
