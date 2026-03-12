\# Smart Alarm Center – PIR Security System 🚨



\## Overview

This project is a smart security alarm center built using Arduino and a PIR motion sensor.

The system detects motion and responds with a full alert sequence including LCD warnings,

police-style LED flashing, and buzzer siren effects.



When no motion is detected, the system remains in safe mode with green indicators.



\## Features

\- Motion detection using PIR sensor

\- 16x2 I2C LCD status display

\- Multi-LED alert system (Red, Blue, Green)

\- Police-style flashing effect

\- Dual-tone buzzer siren

\- Safe mode + Alert mode logic

\- Serial monitoring for debugging



\## Hardware Components

\- Arduino Board (Uno / compatible)

\- PIR Motion Sensor

\- 16x2 LCD with I2C module

\- 2x Green LEDs

\- 2x Blue LEDs

\- 2x Red LEDs

\- Buzzer

\- Resistors

\- Jumper wires



\## System Behavior



\### Safe Mode

\- Green LEDs ON

\- LCD shows "SAFE"

\- Soft periodic beep



\### Alert Mode

\- LCD shows "ALERT! Motion Detected!"

\- Red and Blue LEDs flash alternately

\- Siren sound generated

\- Serial monitor logs detection



\## Technical Notes

\- Uses LiquidCrystal\_I2C library

\- Tone() function used for siren effect

\- Structured conditional logic for system states



\## Future Improvements

\- Add keypad for password control

\- Add GSM module for SMS alerts

\- Add ESP8266 for IoT integration

\- Add logging system



\## Author

Ahmed Ismael – Engineering Student

