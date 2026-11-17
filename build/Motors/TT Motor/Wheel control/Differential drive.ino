//Differential drive example -- two motors driving robot in motion sequence

#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *myMotorL = AFMS.getMotor(1);
Adafruit_DCMotor *myMotorR = AFMS.getMotor(2);

int speed = 150;

void setup() {
  Serial.begin(9600);
  AFMS.begin();
}

void loop() {

//set speed and go forward for 1 second
  myMotorL->setSpeed(speed);
  myMotorR->setSpeed(speed);
  myMotorL->run(FORWARD);
  myMotorR->run(FORWARD);
  delay(1000);

//turn right for 1 second
  myMotorL->run(FORWARD);
  myMotorR->run(BACKWARD);
  delay(1000);

//turn left for 1 second
  myMotorL->run(BACKWARD);
  myMotorR->run(FORWARD);
  delay(1000);

//reverse for 2 seconds
  myMotorL->run(BACKWARD);
  myMotorR->run(BACKWARD);
  delay(2000);

// stop for 5 seconds
  myMotorL->run(RELEASE);
  myMotorR->run(RELEASE);
  delay(5000);
}
