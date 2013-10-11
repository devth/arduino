#include <TinkerKit.h>
 
//TKMosFet mos(O0);  
 TKPotentiometer pot(I0);

void setup() {
  Serial.begin(9600);      // open the serial port at 9600 bps:    
}
 
 

 
void loop() 
{
  int val = pot.read();
  Serial.println(val);
  delay(200);
}
