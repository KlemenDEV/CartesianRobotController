#include <Servo.h>

Servo servo;

void setup() {
  servo.attach(5);

  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
}

void loop() {
  if(digitalRead(6) == 0) {
    servo.write(140);
  } else if(digitalRead(7) == 0) {
    servo.write(40);
  } else {
    servo.write(90);
  }
}
