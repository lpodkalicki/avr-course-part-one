/**
 * Chapter: Digital I/0
 * Exercise E03:
 * 1) use four-leds-shield
 * 2) connect four-leds-shield's LED1 to attiny-board's PB0
 * 3) connect four-leds-shield's LED2 to attiny-board's PB1
 * 4) connect four-leds-shield's LED3 to attiny-board's PB2
 * 5) connect four-leds-shield's LED4 to attiny-board's PB3
 * 6) connect four-leds-shield's GND to attiny-board's GND
 * 7) set registers DDRB (I/O selection) and PORTB (High/Low state selection) - configure all LEDs as OUTPUT with HIGH state
 */

#include <avr/io.h>

int
main(void)
{

	/* --- setup --- */

        DDRB = 0b00000000;
	PORTB = 0b00000000;

	/* --- loop --- */

        while (1);

        return (0);
}
