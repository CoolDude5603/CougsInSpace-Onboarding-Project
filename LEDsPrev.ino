void setup() {
  // put your setup code here, to run once:
  //set led pins to output
  //set sensor pins to input
  lightBoard board1 = new lightBoard(1, 2 ,3,4 ,5);
  lightBoard board2 = new lightBoard(6,7,8,9,10);
  lightBoard board3 = new lightBoard(11, 12,13,14,15);
  lightBoard board4 = new lightBoard(16,17,18,19,20);
  lightBoard[] boardArray = {board1, board2, board3, board4};  
  for (int i = 0; i < 4; i++){
    for(int j = 1; i < 4; i++){
      pinMode(boardArray[i]->LEDs[j], OUTPUT);//set each LED position to OUTPUT
    }
    pinMode(boardArray[i]->sensorPin, INPUT); // set each sensor to INPUT
  }
}

void loop() {
  for (lightBoard board : boardArray){
    board.shouldBeOn();
  }
}
//parameters: pin number of led
//

class lightBoard(){
  int[4] LEDs;
  const lightThreshold = 50;
  int sensorPin;

  public lightBoard(int sensorPin, int[] LEDs){
    this->sensorPin = sensorPin;
    this->LEDs[0] = led1;
    this->LEDs[1] = led2;
    this->LEDs[2] = led3;
    this->LEDs[3] = led4;
  }

  public void shouldBeOn(){
    int raw_light = analogRead(this.sensorPin);
    int light = map(raw_light, 0, 1023, 0, 100);
    if (light > lightThreshold){
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
}
