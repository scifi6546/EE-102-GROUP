#include <avr/io.h>

int main(){
	DDRB |=_BV(DDB0);
	PORTB |= _BV(PORTB0);

}
