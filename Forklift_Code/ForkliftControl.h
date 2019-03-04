/*
Control functions for the RC car. Basic movement,
like drive forward, backward, rotate left and right.

Note: digitalWrite() is terrible for fine motor control
and is just a terrible idea in general, especially for RC cars.
Use Analog instead.
*/

void rotateRight() {
  digitalWrite(enableL, HIGH);
  digitalWrite(L_fwd, HIGH);
  digitalWrite(L_back, LOW);

  digitalWrite(enableL2, HIGH);
  digitalWrite(L2_fwd, HIGH);
  digitalWrite(L2_back, LOW);

  digitalWrite(enableR, HIGH);
  digitalWrite(R_fwd, LOW);
  digitalWrite(R_back, HIGH);

  digitalWrite(enableR2, HIGH);
  digitalWrite(R2_fwd, LOW);
  digitalWrite(R2_back, HIGH);
}

void rotateLeft() {
  digitalWrite(enableL, HIGH);
  digitalWrite(L_fwd, LOW);
  digitalWrite(L_back, HIGH);

  digitalWrite(enableL2, HIGH);
  digitalWrite(L2_fwd, LOW);
  digitalWrite(L2_back, HIGH);

  digitalWrite(enableR, HIGH);
  digitalWrite(R_fwd, HIGH);
  digitalWrite(R_back, LOW);

  digitalWrite(enableR2, HIGH);
  digitalWrite(R2_fwd, HIGH);
  digitalWrite(R2_back, LOW);
}

void goForward() {
  digitalWrite(enableL, HIGH);
  digitalWrite(L_fwd, HIGH);
  digitalWrite(L_back, LOW);
  
  digitalWrite(enableR, HIGH);
  digitalWrite(R_fwd, HIGH);
  digitalWrite(R_back, LOW);
  
  digitalWrite(enableR2, HIGH);
  digitalWrite(R2_fwd, HIGH);
  digitalWrite(R2_back, LOW);

  digitalWrite(enableL2, HIGH);
  digitalWrite(L2_fwd, HIGH);
  digitalWrite(L2_back, LOW);
}

void goBackward() {
  digitalWrite(enableL, HIGH);
  digitalWrite(L_fwd, LOW);
  digitalWrite(L_back, HIGH);
  
  digitalWrite(enableR, HIGH);
  digitalWrite(R_fwd, LOW);
  digitalWrite(R_back, HIGH);
  
  digitalWrite(enableR2, HIGH);
  digitalWrite(R2_fwd, LOW);
  digitalWrite(R2_back, HIGH);

  digitalWrite(enableL2, HIGH);
  digitalWrite(L2_fwd, LOW);
  digitalWrite(L2_back, HIGH);
}

void closeServo() {
   for (pos = 90; pos <= 220; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
  delay(3000);
  for (pos = 220; pos >= 90; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
}

void resetServo() {
  myservo.write(90);
}

void stop() {
  digitalWrite(enableL, LOW);
  digitalWrite(enableR, LOW);
  digitalWrite(enableL2, LOW);
  digitalWrite(enableR2, LOW);
}
