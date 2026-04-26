#define F_CPU 4000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "keypad.h"
void keypad_init() {
	//0b k4 k3 k2 k1 w4 w3 w2 w1
	DDRA  =  0xF0; // wiersze wejscia, kolumny wyjscia
	PORTA = 0xFF;            // pull-upy na wiersze, kolumny wysoko
}

uint8_t keypad_scan() {
	for(uint8_t col = 0;col < 4;col++)
	{
		PORTA |= 0xF0;
		_delay_us(3);
		PORTA &=  ~(1 << (col + 4)); //stan niski na jednej kolumnie
		_delay_us(3);
		for(uint8_t row = 0; row < 4 ; row++)
		{
			uint8_t odczyt = PINA & 0x0F;
			if ((odczyt & (1<<row)) == 0)
			{
				
				return row*4+col +1;
			}
		}
	}
	
	return 0;
}
