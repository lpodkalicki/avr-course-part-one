/**
 * Chapter: Digital I/0
 * Exercise E04:
 * 1) use rgb-leds-shield
 * 2) connect rgb-leds-shield's LED_RED to attiny-board's PB0
 * 3) connect rgb-leds-shield's LED_GREEN to attiny-board's PB1
 * 4) connect rgb-leds-shield's LED_BLUE to attiny-board's PB2
 * 5) connect rgb-leds-shield's VCC to attiny-board's VCC
 * 6) set registers DDRB (I/O selection) and PORTB (High/Low state selection) - configure all LEDs as OUTPUT with HIGH state
 */

#include <avr/io.h>
#include <util/delay.h>

#define	LED_RED		PB0
#define	LED_GREEN	PB1
#define	LED_BLUE	PB2

int
main(void)
{

        DDRB = 0b00000000;
	PORTB = 0b00000000;

        while (1) {
		 // Light the LED
                PORTB &= ~(1 << LED_RED);       // Clear bit
		_delay_ms(500);

                // Turn off the LED
                PORTB |= (1 << LED_RED);        // Set bit
		_delay_ms(500);
	}

        return (0);
}

