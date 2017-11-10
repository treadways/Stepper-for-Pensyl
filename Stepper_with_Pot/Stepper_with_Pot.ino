
#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor
const int buttonR = 2;
const int buttonG = 3;
const int buttonB = 4;
const int pot = 0; 
int buttonRstate, buttonGstate, buttonBstate, potVali, potValf, changePotVal;

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
  // initialize the serial port:
  Serial.begin(9600);
  pinMode (buttonR, INPUT); //set up botton pin
  pinMode (buttonG, INPUT);
  pinMode (buttonB, INPUT);
}

void loop() {
  buttonRstate = digitalRead(buttonR); //Read HIGH or LOW input
  buttonGstate = digitalRead(buttonG);
  buttonBstate = digitalRead(buttonB);
  
  potVali = analogRead(pot);
  potVali = map(potVali, 0, 1023, 0, 100);

  delay(5);

  potValf = analogRead(pot);
  potValf = map(potValf, 0, 1023, 0, 100);

  changePotVal = potValf - potVali;

  myStepper.setSpeed(50);
  myStepper.step(changePotVal);



  //For buttons
  /*if ((buttonRstate == HIGH) && (buttonGstate == LOW) && (buttonBstate == LOW)) //for red button
  {
  // set the speed at 30 rpm:
  myStepper.setSpeed(33);
  // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  //delay(500);

  // step one revolution in the other direction:
  //Serial.println("counterclockwise");
  //myStepper.step(-stepsPerRevolution);
  //delay(500);
  }
    
    if ((buttonRstate == LOW) && (buttonGstate == HIGH) && (buttonBstate == LOW)) //for green button
  {
  // set the speed at 66 rpm:
  myStepper.setSpeed(66);
  // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  //delay(500);

  // step one revolution in the other direction:
  //Serial.println("counterclockwise");
  //myStepper.step(-stepsPerRevolution);
  //delay(500);
  }

    if ((buttonRstate == LOW) && (buttonGstate == LOW) && (buttonBstate == HIGH))
  {
  // set the speed at 100 rpm:
  myStepper.setSpeed(100);
  // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  //delay(500);

  else 
  {
    myStepper.setSpeed(0);
    Serial.println("clockwise");
    myStepper.step(stepsPerRevolution);
  }

  // step one revolution in the other direction:
  //Serial.println("counterclockwise");
  //myStepper.step(-stepsPerRevolution);
  //delay(500); */
  }


