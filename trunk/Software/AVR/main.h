#include <avr/io.h>
#include <util/delay.h>
#include <util/delay_basic.h>
#include <avr/pgmspace.h>

#define LED1PORT	PORTD
#define LED1		PD0
#define LED2PORT	PORTD
#define LED2		PD1
#define LED3PORT	PORTA
#define LED3		PD1
#define LED4PORT	PORTA
#define LED4		PD0
#define LED5PORT	PORTD
#define LED5		PA2
#define LED6PORT	PORTD
#define LED6		PD3
#define LED7PORT	PORTD
#define LED7		PD4
#define LED8PORT	PORTD
#define LED8		PD5

#define INPUT1PORT	PIND
#define INPUT1		PD6
#define INPUT2PORT	PINB
#define INPUT2		PD0
#define INPUT3PORT	PINB
#define INPUT3		PD1
#define INPUT4PORT	PINB
#define INPUT4		PD2
#define INPUT5PORT	PINB
#define INPUT5		PD3
#define INPUT6PORT	PINB
#define INPUT6		PD4

void SetLed(uint8_t inp);
void PutChar(uint8_t ch,uint8_t delay);
uint8_t ReadInput();
