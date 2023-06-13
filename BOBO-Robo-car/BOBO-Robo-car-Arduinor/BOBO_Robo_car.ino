#include <Servo.h>
Servo s = Servo();
#include <Ultrasonic.h>
Ultrasonic u = Ultrasonic(3, 2);

void setup() {
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  analogWrite(5, 150);
  analogWrite(11, 150);

  Serial.begin(9600);
  s.attach(9);
}

void loop() {
  int num = Serial.read();
  int d = u.read();
  Serial.println(d);
  if (d < 10) {
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    delay(1000);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    delay(1000);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  }
  if (num == '1') {
    int d = u.read();
    Serial.println(d);
    s.write(90);
    if (d < 10) {
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);
    } else {
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      //delay(500);
      //digitalWrite(6, LOW);
      //digitalWrite(7, LOW);
      //digitalWrite(12, LOW);
      //digitalWrite(13, LOW);
    }
  }
  if (num == '2') {
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
  }
  if (num == '3') {
    int d = u.read();
    s.write(150);
    if (d < 10) {
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);
    } else {
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      delay(500);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);
    }
    delay(500);
    s.write(90);
  }
  if (num == '4') {
    int d = u.read();
    s.write(30);
    if (d < 10) {
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);
    } else {
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(13, LOW);
      delay(500);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);
    }
    delay(500);
    s.write(90);
  }
  if (num == '0') {
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  }
}
