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



#define CMD_FUNCTION_SET 0b00101000 -> 8/4bit dataLength ; 2 linie ; font 5x8 ; - ; -
#define CMD_ENTRY_MODE_SET 0b00000110 -> inkrementacja kursora ; brak przesuwania okna
#define CMD_DISPLAY_ON 0b00001100 -> on/off ; kursor off ; brak migania
