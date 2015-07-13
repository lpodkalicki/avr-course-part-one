/**
 * Chapter: Digital I/0
 * Exercise E08:
 * 1) use four-leds-shield and one switch
 * 2) connect four-leds-shield's GND to attiny-board's GND
 * 3) connect four-leds-shield's LED1 to attiny-board's PB0
 * 4) connect SWITCH to attiny-board's GND and to PB4
 * 5) set registers DDRB (I/O selection) and PORTB (High/Low selection):
 *    a) set PB0 as output with LOW state
 *    b) set PB4 as input with HIGH state (it means, _with_ internal pull-up resistor)q
 */

#include <avr/io.h>
#include <util/delay.h>

#define	LED1		PB0
#define	SWITCH		PB4

int
main(void)
{

        DDRB = 0b00000000;
	PORTB = 0b00000000;

        while (1) {

		_delay_ms(10);

		if ((PINB & (1 << SWITCH)) == 0) {

			PORTB ^= (1 << LED1);

			_delay_ms(30);
			while((PINB & (1 << SWITCH)) == 0);
			_delay_ms(30);
		}

	}

        return (0);
}
