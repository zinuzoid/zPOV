#include "main.h"
#include "data.c"

int main()
{
	DDRA=0xFF;
	DDRD=0xFF;

	PORTA=0xFF;
	PORTD=0xFF;

	uint8_t i=0;

	while(1)
	{
		if(i==5) i=0;
		uint8_t tmp=pgm_read_byte(&ledOn[i]);
		SetLed(tmp);
		_delay_ms(250);
		i++;
	}

	return 0;
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
