#include "pinDefs.h"
#include "ForkliftControl.h"
#include <Servo.h>

char val;
long duration, distance;
bool bad;
Servo myservo;
int pos = 0;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(32);
  myservo.write(90);
  pinMode(enableL, OUTPUT);
  digitalWrite(enableL, LOW);
  pinMode(L_fwd, OUTPUT);
  pinMode(L_back, OUTPUT);
  
  pinMode(enableR, OUTPUT);
  digitalWrite(enableR, LOW);
  pinMode(R_fwd, OUTPUT);
  pinMode(R_back, OUTPUT);

  pinMode(enableR2, OUTPUT);
  digitalWrite(enableR2, LOW);
  pinMode(R2_fwd, OUTPUT);
  pinMode(R2_back, OUTPUT);
  
  Serial.begin(9600);

}


void loop() {
  // put your main code here, to run repeatedly:
   if (Serial.available()) {
    val = Serial.read();
   }
   if (val == '0') {
    goForward();
   }
   else if (val == '1') {
    stop();
   }
   else if (val == '2') {
    rotateLeft();
   }
   else if (val == '3') {
    rotateRight();
   }
   else if (val == '4') {
    goBackward();
   }
   else if (val == '7') {
    resetServo();
   }
   else if (val == '8') {
    closeServo();
   }
   delay(10);
}
