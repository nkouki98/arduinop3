#include <Servo.h>
#include <IRremote.h>
Servo s1;
Servo s2;
Servo s3;

int pos = 0;

const int RECV_PIN = 7;

const int motor1pin = 2;
const int motor2pin = 3;
const int motor3pin = 4;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(RECV_PIN);
  s1.attach(8);
  s2.attach(11);
  s3.attach(10);
  // put your setup code here, to run once:
}

void loop() {
  if(IrReceiver.decode()) {
    Serial.println(IrReceiver.decodedIRData.command);

    if(IrReceiver.decodedIRData.command == 64) {
      Serial.println("HERE 64");
      rotateMotor(s1);
      rotateMotor(s2);
      rotateMotor(s3);

    }
    IrReceiver.resume();
  }

}

void rotateMotor (Servo s) {
  Serial.println("R1");
  for (int angle = 0; angle <= 180; angle += 1) {
    //analogWrite(motorPin, map(angle, 0, 120, 0, 255));
    s.write(angle);
    delay(5);
  }
  delay(400);
  Serial.println("R2");
  for (int angle = 180; angle >= 0; angle -= 1) {
    //analogWrite(motorPin, map(angle, 0, 120, 0, 255));
    s.write(angle);
    delay(5);
  }
  delay(400);
}