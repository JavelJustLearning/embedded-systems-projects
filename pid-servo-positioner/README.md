# PID Servo Positioner

A closed-loop position controller using a potentiometer as setpoint input and an SG90 servo 
as the controlled output. Implements a full PID control loop in Arduino C++ from scratch, 
including proportional, integral, and derivative terms, anti-windup clamping, and real-time 
Serial Plotter visualization.

## Key Concepts
Feedback control, steady-state error, integral windup, gain tuning, delta-time calculations

## Components
- Arduino UNO
- SG90 servo motor
- Potentiometer
- Breadboard, jumper wires

## Wiring
- Servo orange wire → pin 9
- Servo red wire → 5V
- Servo brown/black wire → GND
- Potentiometer middle pin → A0
- Potentiometer left pin → 5V
- Potentiometer right pin → GND

## What It Does
Turn the potentiometer to set a target angle between 0° and 180°. The PID controller 
reads the error between the setpoint and current position, then drives the servo to the 
target using proportional, integral, and derivative corrections. The integral term eliminates 
steady-state error, the derivative term dampens overshoot, and gains were tuned empirically 
by observing the Serial Plotter in real time.

## Final Tuned Gains
- Kp = 0.3
- Ki = 1.0
- Kd = 1.25

## Planned Extensions
- Second potentiometer for live gain tuning without re-uploading
- LCD readout displaying setpoint, position, and error in real time
- Anti-windup improvements for better performance across full range
