# Smart Home System 🏠💡

## 📖 Overview
This project is part of the **Standard Embedded Systems Diploma**, implemented on the **ATmega32 Microcontroller**.  
The goal of this project is to design and implement a **Smart Home System** with modular drivers for different sensors and actuators.  

The system provides **automatic lighting, temperature-based fan control, and flame detection with alarm system**, all built from scratch using **Embedded C**.

---

## ✨ Features
- 🌗 **Automatic Lighting Control**  
  - Uses **LDR Sensor** to detect light intensity and control room lighting.  

- 🌡 **Temperature-based Fan Control**  
  - Adjusts fan speed dynamically using **PWM on Timer0** and a **Temperature Sensor**.  

- 🔥 **Flame Detection & Alarm System**  
  - Activates a **buzzer alarm** when flame is detected for safety.  

- 🧩 **Modular Design**  
  - Custom drivers implemented for GPIO, ADC, PWM, and all sensors.

---

## 🛠 Hardware Components
- ATmega32 Microcontroller  
- LDR Sensor  
- Temperature Sensor (LM35 or equivalent)  
- Flame Sensor  
- Fan (DC Motor)  
- Buzzer  
- LEDs  

---

## 💻 Software & Tools
- **Embedded C (AVR-GCC)**  
- **Drivers implemented from scratch** for:
  - GPIO  
  - ADC  
  - PWM (Timer0)  
  - Sensors  
- **Proteus** (for simulation & testing)  

---

## ⚙️ System Architecture
1. **LDR Sensor** → Controls lighting automatically.  
2. **Temperature Sensor + PWM (Timer0)** → Controls fan speed based on temperature.  
3. **Flame Sensor + Buzzer** → Activates alarm on fire detection.  
4. **Drivers** → Each module has its own driver for reusability.  

---


