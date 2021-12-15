import processing.serial.*;

import processing.video.*;

import processing.sound.*;

int NUM_OF_VALUES_FROM_ARDUINO = 1;   /** YOU MUST CHANGE THIS ACCORDING TO YOUR PROJECT **/
int sensorValues[];      /** this array stores values from Arduino **/

String myString = null;

Serial myPort;

Movie defaultClip;
Movie hugClip;

boolean test = true;

void setup() {
  setupSerial();

  fullScreen();
  ;
  defaultClip = new Movie(this, "RobotEdited.mov");
  hugClip = new Movie(this, "face.mp4");
}


void draw() {
  getSerialData();

  defaultClip.play();
  defaultClip.read();
  image(defaultClip, 0, 0);


  if (sensorValues[0] == 0) {

    if (defaultClip.isPlaying() == true) {
      defaultClip.pause();      
      hugClip.play();
      hugClip.read();
      image(hugClip, 0, 0); 

      if (test && hugClip.time() >= hugClip.duration()) {
        hugClip.stop();
        
      }
    }
  }
}



void setupSerial() {
  printArray(Serial.list());
  myPort = new Serial(this, Serial.list()[0], 9600);

  myPort.clear();
  myString = myPort.readStringUntil( 10 );  
  myString = null;

  sensorValues = new int[NUM_OF_VALUES_FROM_ARDUINO];
}




void getSerialData() {
  while (myPort.available() > 0) {
    myString = myPort.readStringUntil( 10 ); // 10 = '\n'  Linefeed in ASCII
    if (myString != null) {
      String[] serialInArray = split(trim(myString), ",");
      if (serialInArray.length == NUM_OF_VALUES_FROM_ARDUINO) {
        for (int i=0; i<serialInArray.length; i++) {
          sensorValues[i] = int(serialInArray[i]);
        }
      }
    }
  }
}
