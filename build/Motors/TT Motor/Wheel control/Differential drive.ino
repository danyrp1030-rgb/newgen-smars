//Differential drive example -- two motors driving robot in motion sequence
//Components Needed: 
    //Adafruit Motorshield V2
    //2 TT motors
    //1 or 2 idle wheels

//include wire and motorshield libraries
#include <Wire.h>
#include <Adafruit_MotorShield.h>

//create controller object
Adafruit_MotorShield AFMS = Adafruit_MotorShield();

//Define motor pins M1 and M2 (there is also M3 and M4, check wiring)
Adafruit_DCMotor *myMotorL = AFMS.getMotor(1);
Adafruit_DCMotor *myMotorR = AFMS.getMotor(2);

//define speed -- speed range is 0 to 255
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
