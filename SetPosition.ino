#include "xArmServoController.h"
#include <SoftwareSerial.h>

// To use SoftwareSerial:
// 1. Uncomment include statement above and following block.
// 2. Update xArmServoController with mySerial.
// 3. Change Serial1.begin to mySerial.begin.

#define rxPin 2
#define txPin 3

SoftwareSerial mySerial = SoftwareSerial(rxPin, txPin);

xArmServoController myArm = xArmServoController(xArm, mySerial);

void setup() {
  mySerial.begin(9600);

  // xArm servo positions
  xArmServo home[] = {{1, 0},
  
    {2, 500},
    {3, 500},
    {4, 500},
    {5, 500},
    {6, 500}
  };

  xArmServo grab[] = {{1, 0},
    {6, 500},
    {4, 1000},
    {5, 400},
    {3, 750}
  };
  
  xArmServo closejaw[] = {{1, 1000},
  
  };

  xArmServo lift[] = {{5, 500},
  {1, 1000}

  };

  xArmServo drop[] = {{4, 1000},
    {3, 750},
    {5, 400},
    {6, 850}
  };

    xArmServo openjaw[] = {{1, 0},
  };
  
  //Set positioin
  myArm.setPosition(home, 6, 2000, true);
  delay(1000);

  // Making it grab
  myArm.setPosition(grab, 6, 2000, true);
  myArm.setPosition(closejaw, 1, 3000, true);
  delay(1000);


  // Getting it to the drop position  
  myArm.setPosition(lift, 4,  2000, true);
  delay(1000);

 myArm.setPosition(drop, 4,  2000, true);
  delay(1000);


  myArm.setPosition(openjaw, 1, 3000, true);
  delay(1000);
  

  //back to preset position 
  myArm.setPosition(home, 5, 2000, true);




}

void loop() {
  // Your code here.
}
