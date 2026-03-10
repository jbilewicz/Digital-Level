#  Digital Level

## 📝 Project Overview
This project is a high-precision digital level based on the **ESP32** microcontroller. It utilizes the **MPU6050** 6-axis accelerometer and gyroscope to measure tilt angles in real-time. When the device reaches a perfectly horizontal position (tilt < 0.30 m/s² on X and Y axes), it triggers an audible alert.

##  Tech Stack
<p align="left">
  <img src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" />
  <img src="https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white" />
  <img src="https://img.shields.io/badge/ESP32-E67E22?style=for-the-badge&logo=espressif&logoColor=white" />
</p>

---

##  Components
- **Microcontroller:** ESP32 DEVKIT V1.
- **Sensor:** MPU6050 (Accelerometer & Gyroscope).
- **Display:** 0.96" SSD1306 OLED (128x64) via I2C.
- **Audio:** Active Buzzer for level notification.
- **Prototyping:** Universal Protoboard (THT).

---

##  Hardware Design & Pinout
The system is powered via USB (5V). Both the sensor and the display share the **I2C bus** (GPIO 21 and 22).

| Component | ESP32 Pin | Function |
| :--- | :--- | :--- |
| **MPU6050 SDA** | GPIO 21 | I2C Data  |
| **MPU6050 SCL** | GPIO 22 | I2C Clock  |
| **SSD1306 SDA** | GPIO 21 | I2C Data  |
| **SSD1306 SCL** | GPIO 22 | I2C Clock  |
| **Active Buzzer**| GPIO 13 | Level Alert (Inverted Logic)  |



---

##  Key Algorithms
1. **Level Detection:** The system monitors `acceleration.x` and `acceleration.y`. If both values fall below `LEVEL_THRESHOLD` (0.30), the device is considered level.
2. **Visual Feedback:** Large text (Size 3) displays X/Y acceleration values, and an "**>>OK<<**" message appears when level.
3. **Inverted Buzzer Logic:** The buzzer is activated by pulling the pin **LOW**.

---

##  Repository Structure
- `/Code` - Arduino/C++ source code (.ino).
- `/Docs` - Full technical report in PDF format.
- `/Images` - Photos of the soldered protoboard.
