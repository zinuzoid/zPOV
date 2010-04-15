#include "main.h"
#include "data.c"

#define LedSync 50

uint8_t ReadDelay()
{
	uint8_t tmp;
	tmp=(PINB>>2)&0b00000111;
	tmp^=tmp>>1;
	tmp^=tmp>>2;
	return tmp;
}

void PutStr(char *str,uint8_t delay)
{
	while(*str)
	{
		PutChar(*str,delay);
		PutChar(*LedBlank,delay);
		str++;
	}
}

int main()
{
	DDRA=0xFF;
	DDRB=0x0;
	DDRD=0b10111111;

	PORTA=0xFF;
	PORTB=0xFF;
	PORTD=0xFF;

	_delay_ms(100);

	while(1)
	{
		PORTD=ReadDelay();
	}

	if(bit_is_set(PIND,PD6))
		PutStr("ABC",LedSync);
	else
		PutStr("XYZ",LedSync);

	while(1)
	{

	}

	return 0;
}

void PutChar(uint8_t ch,uint8_t delay)
{
	if((ch>='A')&&(ch<='Z')) ch-='A';
	else if((ch>='a')&&(ch<='z')) ch-='a';
	for(int i=0;i<=5;i++)
	{
		SetLed(pgm_read_byte(&LedChar[ch][i]));
		for(int n=0;n<=delay;n++) _delay_ms(10);
	}
}

void SetLed(uint8_t inp)
{
	if(inp&0b00000001)
		LED1PORT |= _BV(LED1);
	else
		LED1PORT &= ~_BV(LED1);

	if(inp&0b00000010)
		LED2PORT |= _BV(LED2);
	else
		LED2PORT &= ~_BV(LED2);

	if(inp&0b00000100)
		LED3PORT |= _BV(LED3);
	else
		LED3PORT &= ~_BV(LED3);

	if(inp&0b00001000)
		LED4PORT |= _BV(LED4);
	else
		LED4PORT &= ~_BV(LED4);

	if(inp&0b00010000)
		LED5PORT |= _BV(LED5);
	else
		LED5PORT &= ~_BV(LED5);

	if(inp&0b00100000)
		LED6PORT |= _BV(LED6);
	else
		LED6PORT &= ~_BV(LED6);

	if(inp&0b01000000)
		LED7PORT |= _BV(LED7);
	else
		LED7PORT &= ~_BV(LED7);

	if(inp&0b10000000)
		LED8PORT |= _BV(LED8);
	else
		LED8PORT &= ~_BV(LED8);
}
