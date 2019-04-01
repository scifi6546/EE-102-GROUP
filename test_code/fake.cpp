#include "../arduino.hpp"
#include <stdio.h>
#include <stdlib.h>
void getEvent(int &numEvents,BUTTONS *toModify){
	BUTTONS *color;
	char temp = getc(stdin);
	
	printf("temp: %c\n",temp);
	fflush(stdout);
	numEvents=1;
	if(temp=='r'){
		printf("red selected\n");
		toModify[0]=RED;
	} 
	else if(temp=='b'){
		toModify[0]=BLUE;
		printf("blue selected\n");
	}
	else if(temp=='g'){
		toModify[0]=GREEN;
		printf("green selected\n");
	}else{
		printf("invalid input\n");
		numEvents=0;
	}
	return;
}
void setLight(BUTTONS in){
	if(in == RED)
		printf("RED LED ON\n");
	if(in == BLUE)
		printf("BLUE LED ON\n");
	if(in==GREEN)
		printf("GREEN LED ON\n");
	fflush(stdout);
}
void winGame(){
	printf("BUZZ BUZZ GAME WON!!");
	fflush(stdout);
}
void looseGame(){

	printf("Sad Buz Buz ?? Game LOST!\n");
	fflush(stdout);
}
	
