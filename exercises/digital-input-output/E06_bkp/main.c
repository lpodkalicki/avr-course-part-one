/**
 * Chapter: Digital I/0
 * Exercise E06 (based on E05):
 * 1) use four-leds-shield and one switch
 * 2) connect four-leds-shield's GND to attiny-board's GND
 * 3) connect LED1 to PB0, LED2 to PB1, LED3 to PB2, LED4 to PB3
 * 4) connect SWITCH to attiny-board's VCC and to PB4
 * 5) connect external pull-down resistor (2-10k) to PB4 and GND
 * 6) set registers DDRB (I/O selection) and PORTB (High/Low selection):
 *    a) set PB0, PB1, PB2, PB3 as output with LOW state
 *    b) set PB4 as input with LOW state (it means, _without_ internal pull-up resistor)
 */

#include <avr/io.h>
#include <util/delay.h>

#define	LED1		PB0
#define LED2            PB1
#define LED3            PB2
#define LED4            PB3
#define	SWITCH		PB4
#define	MODE_MAX	(5)

int
main(void)
{
	uint8_t mode = 0;

        DDRB = 0b00001111;	// TODO: wyzerowac
	PORTB = 0b00000000;	// TODO: to samo

        while (1) {

		_delay_ms(10);

		if ((PINB & (1 << SWITCH)) > 0) {

			switch(mode) {
			case 0: PORTB = (1 << LED1); break;
			case 1: PORTB = (1 << LED2); break;
			case 2: PORTB = (1 << LED3); break;
			case 3: PORTB = (1 << LED4); break;
			default: PORTB = 0; break;
			}

			mode = (mode + 1) % MODE_MAX;           // 0, 1, 2, ..., MODE_MAX - 1

			_delay_ms(30);
			//while((PINB & (1 << SWITCH)) > 0);
			_delay_ms(30);
		}

	}

        return (0);
}
