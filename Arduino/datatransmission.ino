
/*
  Treyvor Jannarone, transmission code for arduino, senior project 3/3/2020
*/

#include <TimedAction.h>

int Tx = 13; // tx output set to pin 13
int Rx = 12; // rx input set topin 12
int genID = 2; //id of the generator
int dataBitLength = 5;
const int clock2 = 12;
const int sync = 11;
const int sensor = A0;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  
  pinMode(sync, INPUT);
  pinMode(clock2, OUTPUT);
  
  pinMode(Tx, OUTPUT);     // sets the digital pin as output (Tx)
  pinMode(Rx, OUTPUT);     // sets the digital pin as input  (Rx)
  
}


void clockThread() {
  digitalWrite(clock2, HIGH);
  delay(2000);
  digitalWrite(clock2, LOW);  
  delay(500);
  digitalWrite(clock2, HIGH);
  delay(500);
  digitalWrite(clock2, LOW);
  delay(500);
  digitalWrite(clock2, HIGH);
  delay(500);
  digitalWrite(clock2, LOW);
  delay(500);
  digitalWrite(clock2, HIGH);
  delay(500);
  digitalWrite(clock2, LOW);
  delay(500);
  digitalWrite(clock2, HIGH);
  delay(500);
  digitalWrite(clock2, LOW);
  delay(500);
  digitalWrite(clock2, HIGH);
  delay(500);
  digitalWrite(clock2, LOW);
  delay(500);
}

TimedAction bruhThread = TimedAction(7500,clockThread);

void loop() {
  //bruhThread.check();
  
  //sync here
  while (pulseIn(sync,HIGH)<1500)
  {
     //do nothing waits for sync
     //digitalWrite(14, HIGH);
  }
  
  int value = analogRead(sensor);random((pow(2,dataBitLength)) - 1);
  String genIDB = String(genID,BIN);
  String valueB = String(value,BIN);
  while(genIDB.length() < 3)
  {
    genIDB="0"+genIDB;
  }
  while(valueB.length()<5)
  {
    valueB="0"+valueB;
  }
  Serial.println(genIDB+valueB);
  Serial.println("------"+String(value)+"------");
  delay(1000);
}


