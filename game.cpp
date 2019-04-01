#include "game.hpp"
#include "arduino.hpp"
#define GAME_LENGTH 10
int last = 0;
int a = 123;
int b = 0111;
int c = 32;

BUTTONS input_buffer[GAME_LENGTH];
BUTTONS solve_buffer[GAME_LENGTH];//buffer of combination needed to finish game
//helper functions
BUTTONS randButton(){
	last = (a+last)%c;
	return (BUTTONS) (last%3);
}

void genCombo(){
	for(int i =0;i<GAME_LENGTH;i++){
		solve_buffer[i]=randButton();
	}
	return;
}
char checkGame(){//compares input_buffer and solve_buffer returns 0 if they are the same
	char out = 0;
	for(int i =0;i<GAME_LENGTH;i++){
		if(input_buffer[i]!=solve_buffer[i])
			out=1;	
	}
	return out;

}



int buffer_index=0;
void handle_input(){//gets events and puts them into the input buffer
	int num_events=0;
	BUTTONS temp_input[GAME_LENGTH];
	getEvent(num_events,temp_input);
	for(int i=0;i<num_events;i++){
		if(i+buffer_index<GAME_LENGTH){
			input_buffer[i+buffer_index]=temp_input[i];
		}
	}
	if(buffer_index+num_events<GAME_LENGTH){
		buffer_index+=num_events;
	}else{
		buffer_index=GAME_LENGTH;
	}
}
//prints buttons in in num_buttons times
void print_buttons(BUTTONS *in,int num_buttons){
	for(int i=0;i<num_buttons;i++){
		setLight(in[i]);
	}
}
//game logic
int initGame(){//initilizes all of the things needed for the game
	genCombo();
	print_buttons(solve_buffer,GAME_LENGTH);
	return 0;
}

int loopGame(){
	handle_input();
	//printing out input
	if(buffer_index==GAME_LENGTH){
		char check = checkGame();
		if(check==0){
			winGame();
		}else{
			looseGame();
		}
		return 1;
	}	
	return 0;
}
