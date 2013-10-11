#include <TinkerKit.h>

int ledArray[] = {8, 9, 10, 11, 12};
int count = 0;
int timer = 75;
TKPotentiometer pot(I0);

void setup() {
  Serial.begin(9600);
  for (count=0; count < 5; count++) {
    pinMode(ledArray[count], OUTPUT);
  }
}

int prevVal;

void loop() {
  int state = HIGH;
  int val = pot.read();
  Serial.println(val);


  for (count=0; count < 5; count++) {
    analogWrite(ledArray[count], val * .22);
    // delay(timer);
  }
  
  prevVal = val;
}


void fade(int ledPin) {
  // fade in from min to max in increments of 5 points:
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) { 
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);         
    // wait for 30 milliseconds to see the dimming effect    
    delay(30);                            
  } 

  // fade out from max to min in increments of 5 points:
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) { 
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);         
    // wait for 30 milliseconds to see the dimming effect    
    delay(30);                            
  } 
}

