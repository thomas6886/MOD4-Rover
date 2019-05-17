#include <Wire.h>
#include <EVShield.h>
#include <EVs_NXTTouch.h>
#include <NewPing.h>

EVShield evshield(0x34,0x36);
EVs_NXTTouch touchSensor;

//Ultrasonic sensor
#define TRIGGER_PIN  3  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     5  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 300 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

/*
 *  SETTINGS 
 */
unsigned int start_speed = 50;  // start speed (speed can be any value between 0-100)
float numCircleDegrees = 960; // number of degrees to turn both motors in order to make a full circle
float numMeterDegrees = 2250; // number of degrees to turn both motors in order to drive 100cm

/*
 *  PROGRAM OBJECTS
 */
unsigned int speed=start_speed;
unsigned int runState=1; // 0: pause ; 1: self-driving ; 2: line-follower ; 3: remote-control 


void setup() {
  // Open serial communication:
  Serial.begin(9600);

  // EVshield:
  evshield.init( SH_HardwareI2C );

  //Touch sensor
  touchSensor.init( &evshield, SH_BAS1 );

  // Reset all motors
  evshield.bank_a.motorReset();
  evshield.bank_b.motorReset();

  if ( evshield.getButtonState(BTN_GO) ) {
    if(runState == 0){
      runState = 1;
    }
    else {
      runState = 0;
    }
  }

}

void loop() {
  
  switch(runState){
    case 0:
      //PAUSE
      break;
    case 1:
      //SELF-DRIVING
      selfDrivingLoop();
      break;
    default:
      //DO NOTHING
      break;
  }

}
