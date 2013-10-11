#include <TinkerKit.h>

int sensorPin = A1;
int sensorValue = 0;
int threshold = 100;
int toneDuration = 262;
int toneFreq = 462;
int speakerPin = 8;
TKPotentiometer pot(I0);

void setup(){
  Serial.begin(9600);
}

void loop(){
  sensorValue = analogRead(sensorPin);
  if (sensorValue > threshold) {
    float potVal = pot.read();
    int f = 20 + (potVal / 1.5f);
    
    Serial.print("Sensor = ");
    Serial.print(sensorValue, DEC);
    Serial.print(", Pot = ");
    Serial.print(potVal, DEC);
    Serial.print(", Freq = ");
    Serial.println(f, DEC);
    
    tone(speakerPin, f, toneDuration);
  }
  delay(10);
}
