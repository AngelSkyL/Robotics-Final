#include <Servo.h>
Servo RightElbow;
Servo RightShoulder;
Servo LeftElbow;
Servo LeftShoulder;

void setup() {
  Serial.begin(9600);
  RightElbow.attach(9);
  RightShoulder.attach(8);
  LeftElbow.attach(7);
  LeftShoulder.attach(6);

}

void loop() {

  //Right Shoulder

        for (int angle = 90; angle <= 180; angle += 1) {
    RightElbow.write(angle);
    delay(15);

      }

        for (int angle = 180; angle >= 90; angle -= 1) {
    RightElbow.write(angle);
    delay(30);
      
        }
}



//  Right Elbow Movement
   for (int angle = 180; angle >= 90; angle -= 1) {
    RightElbow.write(angle);
    delay(15);

   }

     for (int angle = 90; angle <= 180; angle += 1) {
    RightElbow.write(angle);
    delay(30);


     }
}
