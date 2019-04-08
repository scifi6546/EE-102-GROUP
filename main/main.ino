#include "game.hpp"
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
int lastValue = 0;
bool toggledSwitch(){
  int a = analogRead(A0);
    if(lastValue==a){
      lastValue=a;
      return false;
    }else if(abs(a-lastValue)>800){
      lastValue=a;
      return true;
    }
    lastValue=a;
    return false;
    
}
int count=0;
void loop() {
 bool toggle=toggledSwitch();
  count++;
  //if(count%40==0)
    //Serial.println(analogRead(A0));
  if(toggle)
    Serial.println("switch toggled");
  
}
