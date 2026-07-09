#include <Servo.h>
Servo myServo;  

//Declaration of integers 
int potPin = A0;
int sensorValue;
int servoAngle = 90;
int setpoint;

//Declaration of unsigned long
unsigned long delta_time;
unsigned long currentLoopTime;
unsigned long previousLoopTime;

//Declaration of double
double kp = 0.3;
double ki = 1.0;
double kd = 1.25;
double error = 0;
double integral = 0;
double derivative = 0;
double last_error = 0;
double output = 0;


//Setup for loop
void setup(){
  myServo.attach(9);
  Serial.begin(9600);
  previousLoopTime = millis();
}

//Loop for Arduino
void loop(){
  sensorValue = analogRead(potPin);
  setpoint = map(sensorValue,0,1023,0,180);
  currentLoopTime = millis();
  delta_time = currentLoopTime - previousLoopTime;

  //Calculations for PID
  error = setpoint - servoAngle;
  integral = integral + (error * (delta_time/1000.0));
  integral = constrain(integral, -180, 180);
  derivative = (error - last_error) / delta_time;
  output = (kp * error) + (ki * integral) + (kd * derivative);
  output = constrain(output, 0, 180);

  myServo.write(output);
  servoAngle = (int)output;

  last_error = error;
  previousLoopTime = currentLoopTime;

//Serial Prints for PID Controller
  Serial.print("SP:"); Serial.println(setpoint);
  Serial.print("OUT:"); Serial.println(output);
  Serial.print("ERR:"); Serial.println(error);
  Serial.print("INT:"); Serial.println(integral);
  delay(20);
}

