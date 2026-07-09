# Ultrasonic Distance Alarm

A proximity detection system using an HC-SR04 ultrasonic sensor that triggers 
audio and visual alerts when an object is detected within a set distance threshold. 
Displays real-time distance readings on an LCD1602 screen with LED indicators and a buzzer alarm.

## Key Concepts
Ultrasonic sensing, pulse-width measurement, serial communication, threshold logic, LCD display output

## Components
- Arduino UNO
- HC-SR04 ultrasonic sensor
- LCD1602 display
- Potentiometer (contrast)
- Active buzzer
- LEDs (red, yellow, green)
- Resistors, breadboard

## Wiring
- HC-SR04 TRIG → pin 9
- HC-SR04 ECHO → pin 10
- LCD1602 → standard parallel wiring
- Active buzzer → pin 8
- Green LED → pin 4
- Yellow LED → pin 3
- Red LED → pin 2

## What It Does
The HC-SR04 sends an ultrasonic pulse and measures the time for the echo to return, 
converting it to a distance in centimeters. Distance is displayed live on the LCD1602. 
As an object moves closer, LEDs change from green to yellow to red and the buzzer 
activates below the minimum threshold. Serial output streams distance values for 
external logging via Python.

## Planned Extensions
- Python serial reader for live data logging
- Matplotlib polar plot visualization
- Distance history graphing over time
