# 🧠 Embedded Systems Workshop — ATmega32A (14 Days)

Welcome to my **Embedded Systems Workshop Repository**!  
This repo documents my 14-day journey of learning and implementing **Microcontroller Programming** using the **ATmega32A** in both **Assembly** and **C language**, along with **Proteus simulations** and **hardware interfacing**. ⚙️💡

---

## 🧩 Tools & Environment
- 🧠 **Microcontroller**: ATmega32A  
- 💻 **IDE**: Atmel Studio 7  
- 🔌 **Programmer**: Extreme Burner  
- 🧪 **Simulation**: Proteus 8 Professional  
- 📄 **Documentation**: PDF with code explanation and screenshots  

---

## 📅 Workshop Overview

| Day | Topic | Description | Folder |
|-----|--------|--------------|--------|
| 01 | Introduction to Atmega32A | Basic I/O Ports, DDRx, PINx, and PORTx registers | [/Day01_Basics](./Day%201) |
| 02 | LED Blink in Assembly | Writing, assembling, and simulating your first LED blink | [/Day02_LED_Assembly](./Day%202) |
| 03 | LED Blink in C | Same project in Embedded C using Atmel Studio | [/Day03_LED_C](./Day%203) |
| 04 | Switch Interfacing | Digital input handling and debouncing | [/Day04_Switch_Input](./Day%204) |
| 05 | 7-Segment Display | Displaying digits with port manipulation | [/Day05_7Segment](./Day%205) |
| 06 | LCD Display | Sending commands and data to 16x2 LCD | [/Day06_LCD_Display](./Day%206) |
| 07 | ADC Basics | Analog-to-Digital conversion with potentiometer input | [/Day07_ADC](./Day%207) |
| 08 | Temperature Sensor | Reading LM35 data through ADC | [/Day08_Temperature_Sensor](./Day%208) |
| 09 | PWM Signal | Controlling brightness or motor speed using PWM | [/Day09_PWM](./Day%209) |
| 10 | UART Communication | Serial communication between PC and ATmega32A | [/Day10_UART](./Day%2010) |
| 11 | Interrupts | External and Timer interrupts usage | [/Day11_Interrupts](./Day%2011) |
| 12 | Timer | Using timers for delay and event control | [/Day12_Timers](./Day%2012) |
| 13 | Motor Control | DC motor control via driver IC (L293D) | [/Day13_Motor_Control](./Day%2013) |
| 14 | Final Project | Sensor-based automation or integration of multiple modules | [/Day14_Final_Project](./Day%2014) |

---

## 📁 Folder Structure

```

Embedded-Systems-Workshop/
│
├── Day01_Basics/
│   ├── main.asm
│   ├── main.c
│   ├── simulation.pdsprj
│   └── Report.pdf
│
├── Day02_LED_Assembly/
│   ├── LED.asm
│   ├── LED_Simulation.pdsprj
│   └── Report.pdf
│
├── ...
│
└── README.md

````

---

## 🚀 How to Use
1. Clone the repository  
   ```bash
   git clone https://github.com/Thejasvenan/Embedded-Systems-ATmega32A-Workshop.git
   ````

2. Open the project folder in **Atmel Studio**
3. Load `.pdsprj` file in **Proteus** to simulate
4. Check the corresponding **PDF report** for documentation

---

## 🧠 Key Learning Outcomes

* Mastered Atmega32A register-level programming
* Learned to simulate and test embedded circuits in Proteus
* Gained hands-on experience with ADC, UART, PWM, LCD, and Interrupts
* Developed confidence in debugging both software and hardware
---

## 👨‍💻 Author

**Thejasvenan**
🎓 Mechatronics Engineering Undergraduate
🚀 Passionate about Embedded Systems, Robotics & AI

⭐ *If you found this repository helpful, give it a star!*
