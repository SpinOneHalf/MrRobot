#include <Wire.h>

#include <Servo.h>

#include <MPU9255.h>


/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:

#include <SoftwareSerial.h>

#include <TinyGPS.h>

MPU9255 mpu;
TinyGPS gps;
SoftwareSerial ss(4, 3);


int ESN_MIN=1000;
int ESN_MAX=2000;
int ESN_PIN=5;
float full_power=0;
float zero_power=77.5;
float full_reverse=110;
float start_zero=90.5;
int serial_rate=9600;
Servo ESC;  
// the setup routine runs once when you press reset:
void setup() { 
  Serial.begin(serial_rate);
  ESC.attach(ESN_PIN,ESN_MIN,ESN_MAX);
  ESC.write(zero_power);
  delay(1000);
}


// the loop routine runs over and over again forever:
void loop() {
  
}
void set_motor(float p){
  if (p>=0){
    float power_scaled=(1-p)*zero_power;
    ESC.write(power_scaled);
  }
  else{
    float power_scaled=(-1*p)*(full_reverse-start_zero)+start_zero;
    ESC.write(power_scaled);
  }
}

