/**
 * Chapter: Digital I/0
 * Exercise E01:
 * 1) use four-leds-shield
 * 2) connect four-leds-shield's LED2 to attiny-board's PB2
 * 3) connect four-leds-shield's LED4 to attiny-board's PB4
 * 4) connect four-leds-shield's GND to attiny-board's GND
 * 5) set registers DDRB (I/O selection) and PORTB (High/Low selection) to light the LED2 and LED4
 */

#include <avr/io.h>

int
main(void)
{

        DDRB = 0b00000000;
	PORTB = 0b00000000;

        while (1);

        return (0);
}
