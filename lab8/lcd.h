
#ifndef LCD_H_
#define LCD_H_

void lcd_set_instruction_transmission_mode();
void lcd_set_data_transmission_mode();
void lcd_begin_transmission();
void lcd_end_transmission();
void lcd_set_4bits(uint8_t nibble);
void lcd_set_port_lower_nibble(uint8_t data);
void lcd_set_port_upper_nibble(uint8_t data);
void lcd_write_byte(uint8_t data);
void lcd_write_command(uint8_t command);
void lcd_write_character(uint8_t character);
void lcd_init();
void lcd_write_string(uint8_t* data);
void lcd_move_cursor_to(uint8_t row, uint8_t column);
void lcd_clear_characters(uint8_t row, uint8_t col, uint8_t n_characters);
void lcd_clear();
void lcd_return_home();
void lcd_shift_window_left();
void lcd_shift_window_right();
void lcd_define_new_character(uint8_t* znak, uint8_t slot);


#endif /* LCD_H_ */
