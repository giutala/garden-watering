#include <Wire.h>
#include "DS1307.h"

DS1307 clock;  //define a object of DS1307 class

//now the variables to store the data
DS1307 watering_t1;         //watering time as an object of DS1307 class
DS1307 watering_t2;         //watering time as an object of DS1307 class
int watering_thresh = 0;    //percentage for humidity percentage above which watering will not be triggered
int watering_duration = 0;  //how long to water it for
int humidity_sensor = 0;    //this variable will store the feedback from the humidity sensor

const int maxCommandLength = 32;
char commandText[maxCommandLength] = { 0 };

bool receivingCommand = false;
bool commandReady = false;
int commandLength = 0;

void setup() {
  Serial.begin(9600);
  clock.begin();  // setup connection to device

  Serial.println("Please insert the instructions for configuration of the controller.");
  Serial.println("Commands start with '/' and end with newline");
}
void loop() {
  // loop that goes on forever until power shuts off
  receiveCommand();
  if (commandReady) {
    Serial.print("Received command: ");
    Serial.println(commandText);
    commandReady = false;
  }

  //every time the hour on the clock corresponds to the one to water
  //run a check on humidity and based on it trigger the water
  //run code for running water
  //save into memory info regarding this run
  //somewhere add continous check of state pump
}

void receiveCommand() {
  while (!commandReady && Serial.available() > 0) {
    char next = Serial.read();
    if (next == '/') {
      // start a new command, even if currently receiving one
      receivingCommand = true;
      commandLength = 0;
      commandText[commandLength++] = next;
    } else if (receivingCommand) {
      if (next == '\n' || commandLength == maxCommandLength - 1) {
        // finish reading this command
        commandText[commandLength] = 0;
        receivingCommand = false;
        commandReady = true;
      } else {
        // just add this character
        commandText[commandLength++] = next;
      }
    }
  }
}

/*Function: Display time on the serial monitor*/
void printTime() {
  clock.getTime();
  Serial.print(clock.hour, DEC);
  Serial.print(":");
  Serial.print(clock.minute, DEC);
  Serial.print(":");
  Serial.print(clock.second, DEC);
  Serial.print("	");
  Serial.print(clock.month, DEC);
  Serial.print("/");
  Serial.print(clock.dayOfMonth, DEC);
  Serial.print("/");
  Serial.print(clock.year + 2000, DEC);
  Serial.print(" ");
  Serial.print(clock.dayOfMonth);
  Serial.print("*");
  switch (clock.dayOfWeek)  // Friendly printout the weekday
  {
    case MON:
      Serial.print("MON");
      break;
    case TUE:
      Serial.print("TUE");
      break;
    case WED:
      Serial.print("WED");
      break;
    case THU:
      Serial.print("THU");
      break;
    case FRI:
      Serial.print("FRI");
      break;
    case SAT:
      Serial.print("SAT");
      break;
    case SUN:
      Serial.print("SUN");
      break;
  }
  Serial.println(" ");
}
