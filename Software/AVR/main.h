#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>

#define LED1PORT PORTD
#define LED1 PD5
#define LED2PORT PORTD
#define LED2 PD4
#define LED3PORT PORTD
#define LED3 PD3
#define LED4PORT PORTD
#define LED4 PD2
#define LED5PORT PORTA
#define LED5 PA0
#define LED6PORT PORTA
#define LED6 PD1
#define LED7PORT PORTD
#define LED7 PD1
#define LED8PORT PORTD
#define LED8 PD0

void SetLed(uint8_t inp);
