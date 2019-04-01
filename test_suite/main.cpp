#include "../arduino.hpp"
#include "../game.hpp"
#include <stdio.h>

int main(){
	initGame();
	while(0==0){

		loopGame();
	}
	printf(" no it's not  \n");
	return 0;
}
void getEvent(int &numEvents,BUTTONS* toModify){
	//todo implement
}
void setLight(BUTTONS in){
	//todo implement
}
void winGame(){
	//todo implement
}
void looseGame(){
	//todo implement
}

