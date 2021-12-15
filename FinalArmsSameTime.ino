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


int sens = 9;

void setup() {
  Serial.begin(9600);
  pinMode(sens, INPUT);
  RightShoulder.attach(7);    // 110 to 180
  RightElbow.attach(6);       // 100 to 180
  LeftShoulder.attach(5);     // 110 to 50
  LeftElbow.attach(3);        // 120 to 30


  RightShoulder.write(120);
  RightElbow.write(100);
  LeftShoulder.write(110);
  LeftElbow.write(120);
}
void loop() {

  int Sens = digitalRead(sens);
  Serial.print(Sens);
  Serial.println(); // add linefeed after sending the last sensor value
  delay(100);
  
 if (Sens == 0) {

    //// Shoulders Up
    for ( angleRS = 120; angleRS <= 180; angleRS += 1) {
      RightShoulder.write(angleRS);
      angleLS =  round(map (angleRS, 120, 180, 110, 50));
      LeftShoulder.write(angleLS);
      delay(15);
    }


    //// Elbows In
    for ( angleRE = 100; angleRE <= 180; angleRE += 1) {
      RightElbow.write(angleRE);
      angleLE = round(map (angleRE, 100, 180, 120, 30));
      LeftElbow.write(angleLE);
      delay(15);
    }

    delay (3000);

    //// Elbows Out
    for (angleRE = 180; angleRE >= 100; angleRE -= 1) {
      RightElbow.write(angleRE);
      angleLE = round( map(angleRE, 180, 100, 30, 120));
      LeftElbow.write(angleLE);
      delay(30);
    }


    //// Shoulders Down
    for (angleRS = 180; angleRS >= 120; angleRS -= 1) {
      RightShoulder.write(angleRS);
      angleLS = round( map( angleRS, 180, 120, 50, 110));
      LeftShoulder.write(angleLS);
      delay(30);
    }

    delay(5000);

  }
}
//}
