#include <TinkerKit.h>
 
TKMosFet mos(O0);  
TKPotentiometer pot(I0);

void setup() {
  Serial.begin(9600);
}
 
 
void loop() 
{
  int val = pot.read();
  mos.write(val);
  Serial.println(val, DEC);
  delay(10);
}
