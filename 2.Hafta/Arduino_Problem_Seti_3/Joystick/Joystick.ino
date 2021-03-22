#include <Servo.h>  
#include <Joystick.h>

int sag = A0; 
int sol = A1; 

Servo servoM1; 
Servo servoM2;
int motorbir = 0;  
int motoriki = 0;

void setup() { 
  servoM1.attach(5); 
  servoM2.attach(6);  

}
void loop() {
  motorbir = analogRead(sag);
  motorbir = map(motorbir, 0, 1023, 0, 180);
  servoM1.write(motorbir);              

  
  motoriki = analogRead(sol);
  motoriki = map(motoriki, 0, 1023, 0, 90);
  servoM2.write(motoriki);              

     
}
