#include "BluetoothSerial.h"
BluetoothSerial SerialBT;

#define IN1 25
#define IN2 26
#define IN3 27
#define IN4 14

String cmd = "";

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_CAR");

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  stopCar();
  delay(1000);
}

void loop() {

  while (SerialBT.available()) {
    char c = SerialBT.read();

    if (c == '0') {   
      processCommand(cmd);
      cmd = "";
    } else {
      cmd += c;
    }
  }
}
void processCommand(String c) {

  Serial.println(c);

  if (c == "F") forward();
  else if (c == "B") backward();
  else if (c == "L") left();
  else if (c == "R") right();
  else if (c == "S") stopCar();
}
void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void right() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void stopCar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}