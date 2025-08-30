# energy-efficient-streetlight
Energy-efficient streetlight system using ambient light sensors and Arduino
## 📌 Abstract  
This project uses **ambient light sensors** to automatically control streetlights.  
The system ensures that lights are **ON only when required** (during low light conditions) and **OFF during daylight**, thereby reducing energy consumption and promoting smart energy usage.  

## 🛠 Skills Applied  
- C++ Programming  
- Sensor Interfacing (LDR/Light sensors)  
- Arduino programming and debugging  

## ⚙️ Tools Used  
- Arduino IDE  
- Hardware: Arduino board, LDR (Light Dependent Resistor), LEDs  

## 🚀 How it Works  
Daytime (bright) → Streetlight OFF.

Nighttime (dark, LDR < threshold):

No vehicle → LED glows dim (PWM low value).

Vehicle within 500 cm → LED brightens fully.
