#ifndef ARDUINO_HPP
#define ARDUINO_HPP
enum BUTTONS{RED,BLUE,GREEN};
void getEvent(int &numEvents,BUTTONS* toModify);
void setLight(BUTTONS in);
void winGame();//win game event
void looseGame();//loose game event
#endif
