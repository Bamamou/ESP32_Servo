#include <Arduino.h>

/*
  ESP32 Servo
  Use LED on GPIO2
  Use Servo on GPIO2
*/
#include <ESP32Servo.h>
#define ServoPin 2  // Define the pin position of the Servo
Servo my_Servo;     // Create an object of the servo 
// LED on GPIO2
int ledPin = 15;    // Use LED on GPIO2
int Buzer  =4;      // For the buzer 


void setup()
{
    // Set LED as output
    pinMode(ledPin, OUTPUT);    // Set the LedPin as an Output
    my_Servo.attach(ServoPin);    // Set the Servo by attaching its pin to your object my_Servo
    pinMode(Buzer, OUTPUT);   // Set the BuzerPin as output
    // Serial monitor setup
    Serial.begin(115200);
}

void loop()
{
   
    for(int pos=0; pos<=180; pos+=20){   // Move the horn of the Servo from 0 to 180 with a step of 20 degree
       my_Servo.write(pos);                   // apply the above instruction to the Servo
       if(digitalRead(ServoPin)==0){         // If the servo moves light up the LED
          digitalWrite(ledPin, HIGH);        // Turn ON the LED
       }
       tone(Buzer, 5*pos+200, 10);       // Emit a tone from the buzer correcponding to the Servo position
       delay(500);                       // Wait for 500S
      digitalWrite(ledPin, LOW);         // Turn OFF the LED
      delay(100);

     }
     
}