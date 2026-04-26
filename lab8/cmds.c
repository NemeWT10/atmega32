volatile uint8_t* LCD_DDR = &DDRB;
volatile uint8_t* LCD_PORT = &PORTB;
#define RS_LCD 1
#define EN_LCD 0
#define D4_LCD 4
#define D5_LCD 5
#define D6_LCD 6
#define D7_LCD 7
#define CMD_INIT1 0b00110011
#define CMD_INIT2 0b00110010
#define CMD_FUNCTION_SET 0b00101000
#define CMD_ENTRY_MODE_SET 0b00000110
#define CMD_DISPLAY_ON 0b00001100
#define CMD_RET_HOME 0x02
#define CMD_DISPLAY_CLR 0x01
#define CMD_SHIT_LEFT 0b00011000
#define CMD_SHIT_RIGHT 0b00011100






#define CMD_FUNCTION_SET 0b00101000 -> 8/4bit dataLength ; 2 linie ; font 5x8 ; - ; -
#define CMD_ENTRY_MODE_SET 0b00000110 -> inkrementacja kursora ; brak przesuwania okna
#define CMD_DISPLAY_ON 0b00001100 -> on/off ; kursor off ; brak migania
