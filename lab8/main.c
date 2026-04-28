#define F_CPU 4000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "keypad.h"
#include "lcd.h"
int main(void)
{
    lcd_init();
	keypad_init();
	lcd_move_cursor_to(0,2);
	lcd_write_string("Szymon Wojcik");
	lcd_move_cursor_to(1,2);
	lcd_write_string("Tech uPROC");
	uint8_t customChar[8] = {
		0b00011,
		0b00111,
		0b01110,
		0b11100,
		0b11000,
		0b00001,
		0b00011,
		0b00111
	};
	lcd_define_new_character(customChar,0);
	
	lcd_write_character(0);
    while (1) 
    {
		uint8_t key = keypad_scan();
		if (key !=0)
		{
			if( key == 1)
			{
				lcd_clear();
				_delay_ms(50);
			}
			if(key == 2)
			{
				lcd_clear();
				lcd_move_cursor_to(0,0);
				lcd_write_string("Szymon Wojcik");
				lcd_move_cursor_to(1,2);
				lcd_write_string("Tech uPROC");
				_delay_ms(50);
			}
			if(key == 3)
			{
				lcd_shift_window_left();
				_delay_ms(50);
			}
			if(key == 4)
			{
				lcd_shift_window_right();
				_delay_ms(50);
			}
		}
    }
}

