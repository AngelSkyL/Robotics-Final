#include <Servo.h>

// Create a new servo object:
Servo RightShoulder;
Servo RightElbow;
Servo LeftShoulder;
Servo LeftElbow;


// Create a variable to store the servo position:
int angleRS = 0;
int angleRE = 0;
int angleLS = 0;
int angleLE = 0;

//int button = 9;


void setup() {
  Serial.begin(9600);
  // Attach the Servo variable to a pin:
  RightShoulder.attach(7);    // 110 to 180
  RightElbow.attach(6);       // 100 to 180
  LeftShoulder.attach(5);     // 120 to 50
  LeftElbow.attach(3);        // 120 to 30

//  pinMode(button,INPUT);

  
  RightShoulder.write(120);
  RightElbow.write(100);
  LeftShoulder.write(120);
  LeftElbow.write(120);

  
}

void loop() {

//  Button = digitalRead(button);


// if (Button == 1) {
  //// Right Shoulder Up

//  // Sweep from 0 to 180 degrees:
  for (angleRS = 120; angleRS <= 180; angleRS += 1) {
    RightShoulder.write(angleRS);
    delay(15);
  }

//  //// Right Elbow In

  for (angleRE = 100; angleRE <= 180; angleRE += 1) {
    RightElbow.write(angleRE);
    delay(15);
  }

  //// Left Shoulder Up

  for (angleLS = 120; angleLS >= 50; angleLS -= 1) {
    LeftShoulder.write(angleLS);
    delay(15);
  }

//  //// Left Elbow In

  for (angleLE = 120; angleLE >= 30; angleLE -= 1) {
    LeftElbow.write(angleLE);
    delay(15);
  }

delay (3000);

//  //// Right Elbow Out

  for (angleRE = 180; angleRE >= 100; angleRE -= 1) {
    RightElbow.write(angleRE);
    delay(30);

  }

  //// Right Shoulder Down

  //  // And back from 180 to 0 degrees:
  for (angleRS = 180; angleRS >= 120; angleRS -= 1) {
    RightShoulder.write(angleRS);
    delay(30);
  }


  //// Left Elbow Out

  for (angleLE = 30; angleLE <= 120; angleLE += 1) {
    LeftElbow.write(angleLE);
    delay(30);
  }

  //// Left Shoulder Down

  for (angleLS = 50; angleLS <= 120; angleLS += 1) {
    LeftShoulder.write(angleLS);
    delay(30);
  }


  delay(5000);
// }
}
