#include <TinkerKit.h>
 
TKMosFet mos(O0);  
TKPotentiometer pot(I0);

void setup() {

}
 
 
void loop() 
{
  int val = pot.read();
  mos.write(val);
  delay(10);
}
