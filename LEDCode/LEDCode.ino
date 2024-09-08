//define board object containing 4 LEDs and 1 light sensor
class LightBoard {
  public:
    int LEDs[4];
    int LIGHT_THRESHOLD = 50;
    int sensorPin;
    //direction defined as an int array [x,y]
    int direction[2];

    LightBoard(int theSensorPin, int led1, int led2, int led3, int led4) {
      sensorPin = theSensorPin;
      LEDs[0] = led1;
      LEDs[1] = led2;
      LEDs[2] = led3;
      LEDs[3] = led4;
    }

    LightBoard(){
    }

    //if enough light is detected, turn on LEDs
    void shouldBeOn(){
      //detect and quantify light amount
      int light = getLight();
      //turn on LEDs if light amount is enough
      if (light > LIGHT_THRESHOLD){
        for (int i = 0; i < 4; i++){
          digitalWrite(LEDs[i], HIGH);
        }
      } 
      else {
        for (int i = 0; i < 4; i++){
          digitalWrite(LEDs[i], LOW);
        }
      }
    }
    void setDirection(int dir[2]){
      direction[1] = dir[1];
      direction[2] = dir[2];
    }
    
    int getLight(){
      int raw_light = 0;
      raw_light = analogRead(sensorPin);
      int light = map(raw_light, 0, 1023, 0, 100);
      return light;
    }
};

//create array of boards
LightBoard boardArray[4];
//define directions
int FORWARD[2] = {0,1};
int BACKWARD[2] = {0,-1};
int LEFT[2] = {-1,0};
int RIGHT[3] = {1,0};

void setup() {
  //create individual boards and set pin numbers
  //first pin is Light Sensor, 2nd-4th are LEDs
  LightBoard board1(1, 2, 3, 4, 5);
  LightBoard board2(6, 7, 8, 9, 10);
  LightBoard board3(11, 12, 13, 14, 15);
  LightBoard board4(16, 17, 18, 19, 20);

    //set board directions
    board1.setDirection(FORWARD);
    board2.setDirection(RIGHT);
    board3.setDirection(BACKWARD);
    board4.setDirection(LEFT);

    
    //add all 4 boards to an array
    boardArray[1] = board1;
    boardArray[2] = board2;
    boardArray[3] = board3;
    boardArray[4] = board4;


  //loop through arrays to set pin modes
  for (int i = 0; i < 4; i++){
    for(int j = 1; i < 4; i++){
      pinMode(boardArray[i].LEDs[j], OUTPUT);//set each LED position to OUTPUT
    }
    pinMode(boardArray[i].sensorPin, INPUT); // set each sensor to INPUT
  }
}

void loop() {
  //repeatedly test for light on each board and turn on light
  for (LightBoard board : boardArray){
    board.shouldBeOn();
  }
}

void getLightDirection(){
  
}
