#define F_CPU 4000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "keypad.h"
#define RS_LCD 1
#define EN_LCD 0
#define D4_LCD 4
#define D5_LCD 5
#define D6_LCD 6
#define D7_LCD 7
#define LCD_INIT1 0b00110011
#define LCD_INIT2 0b00110010
#define LCD_FUNCTION_SET 0b101000
#define LCD_ENTRY_MODE_SET 0b110
#define LCD_CLR 0x01
#define LCD_RET_HOME 0b10
#define LCD_DISPLAY_ON 0b1100
#define LCD_DISPLAY_OFF 0b1000
#define LCD_SHIFT_RIGHT 0b11100
#define LCD_SHIFT_LEFT 0b11000
#define LCD_SET_DDRAM_ADDR 0x80
#define LCD_SET_CGRAM_ADDR 0x40
volatile uint8_t *LCD_DDR = &DDRB;
volatile uint8_t *LCD_PORT = &PORTB;
void lcd_set_instruction_transmission_mode()
{
	*LCD_PORT &= ~(1<<RS_LCD);
	_delay_us(2);
}
void lcd_set_data_transmission_mode(){
	*LCD_PORT |= (1<<RS_LCD);
	_delay_us(2);
}
void lcd_begin_transmission(){
	*LCD_PORT |= (1<<EN_LCD);
	_delay_us(2);
}
void lcd_end_transmission(){
	*LCD_PORT &= ~(1<<EN_LCD);
	_delay_us(2);
}
void lcd_set_4bits(uint8_t nibble)
{
	if(nibble & 0b1000)
	*LCD_PORT |= (1<<D7_LCD);
	if(nibble & 0x04)
	*LCD_PORT |= (1<<D6_LCD);
	if(nibble & 0x02)
	*LCD_PORT |= (1<<D5_LCD);
	if(nibble & 0x01)
	*LCD_PORT |= (1<<D4_LCD);
	_delay_us(2);
	
}
void lcd_set_port_lower_nibble(uint8_t data)
{
	*LCD_PORT &= ~((1<<D4_LCD)|(1<<D5_LCD)|(1<<D6_LCD)|(1<<D7_LCD));
	_delay_us(2);
	data = data & 0x0F;
	lcd_set_4bits(data);
	_delay_us(2);
}
void lcd_set_port_upper_nibble(uint8_t data)
{
	*LCD_PORT &= ~((1<<D4_LCD)|(1<<D5_LCD)|(1<<D6_LCD)|(1<<D7_LCD));
	_delay_us(2);
	data = (data & 0xF0) >>4;
	lcd_set_4bits(data);
	_delay_us(2);
}
void lcd_write_byte(uint8_t data)
{
	lcd_set_port_upper_nibble(data);
	lcd_begin_transmission();
	_delay_us(2);
	lcd_end_transmission();
	_delay_ms(4);
	
	lcd_set_port_lower_nibble(data);
	lcd_begin_transmission();
	_delay_us(2);
	lcd_end_transmission();
	_delay_ms(4);
}
void lcd_write_command(uint8_t command){
	lcd_set_instruction_transmission_mode();
	_delay_us(2);
	lcd_write_byte(command);
}
void lcd_write_character(uint8_t character){
	lcd_set_data_transmission_mode();
	_delay_us(2);
	lcd_write_byte(character);
}

void lcd_init()
{
	_delay_ms(50);
	*LCD_DDR |= (1<<RS_LCD)|(1<<EN_LCD)|(1<<D4_LCD)|(1<<D5_LCD)|(1<<D6_LCD)|(1<<D7_LCD);
	_delay_us(2);
	lcd_write_command(LCD_INIT1);
	
	lcd_write_command(LCD_INIT2);
	_delay_ms(2);
	lcd_write_command(LCD_FUNCTION_SET);
	lcd_write_command(LCD_DISPLAY_OFF);
	lcd_write_command(LCD_CLR);
	_delay_ms(2);
	lcd_write_command(LCD_ENTRY_MODE_SET);
	lcd_write_command(LCD_DISPLAY_ON);
	lcd_write_command(LCD_RET_HOME);
	_delay_ms(2);
	lcd_write_command(LCD_CLR);
	_delay_ms(3);
	
}
void lcd_write_string(uint8_t* data){
	uint16_t i =0 ;
	while(data[i])
	{
		lcd_write_character(data[i]);
		i++;
	}
}
void lcd_move_cursor_to(uint8_t row, uint8_t column){
	lcd_write_command(LCD_SET_DDRAM_ADDR | (0x40*row+column));
	
}
void lcd_clear_characters(uint8_t row, uint8_t col, uint8_t n_characters){
	lcd_move_cursor_to(row,col	);
	for(uint8_t i=0;i<n_characters;i++)
	{
		lcd_write_character(' ');
	}
}
void lcd_clear(){
	lcd_write_command(LCD_CLR);
}
void lcd_return_home()
{
	lcd_write_command(LCD_RET_HOME);
}
void lcd_shift_window_left(){
	lcd_write_command(LCD_SHIFT_LEFT);
}
void lcd_shift_window_right(){
	lcd_write_command(LCD_SHIFT_RIGHT);
}
void lcd_define_new_character(uint8_t* znak, uint8_t slot)
{
	lcd_write_command(LCD_SET_CGRAM_ADDR | (slot*8));
	for (uint8_t i=0;i<8;i++)
	{
		lcd_write_character(znak[i]);
	}
	lcd_move_cursor_to(0,0);
}
