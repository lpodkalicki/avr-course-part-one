/**
 * Chapter: Digital I/0
 * Exercise E02:
 * 1) use four-leds-shield
 * 2) connect four-leds-shield's LED1 to attiny-board's PB0
 * 3) connect four-leds-shield's LED2 to attiny-board's PB1
 * 4) connect four-leds-shield's GND to attiny-board's GND
 * 5) set registers DDRB (I/O selection) and PORTB (High/Low selection) to light the LED1 and LED2
 */

#include <avr/io.h>

int
main(void)
{

        DDRB = 0b00001111;
	PORTB = 0b00001111;

        while (1);

        return (0);
}
