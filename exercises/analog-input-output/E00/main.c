/**
 * Chapter: Analog I/O
 * Exercise E00:
 * 1) rgb-leds-shield
 * 2) connect rgb-leds-shield's LED_GREEN to attiny-board's PB0
 * 3) connect rgb-leds-shield's VCC to attiny-board's VCC
 * 4) set registers DDRB (I/O selection) and PORTB (High/Low selection) - configure PB0 as OUTPUT with HIGH state
 */

#include <avr/io.h>
#include <util/delay.h>

#define	LED_PIN		PB0

int
main(void)
{
	uint8_t i;

	/* --- setup --- */

	DDRB = 0b00000000;
	PORTB = 0b00000000;
	TCCR0A = (1<<COM0A1)|(1<<WGM00); 	// Connect PWM to pin on timer 0 and channel A; set timer PWM mode
	TCCR0B = 1<<CS01;			// Set prescaler to 8 (CLK/8)

	/* --- loop --- */

        while (1) {

		// Fade-in effect
                for (i = 0; i < 128; ++i) {
			OCR0A = i;
                        _delay_ms(10);
                }

                // Fade-out effect
                for (i = 128; i > 0; --i) {
			OCR0A = i;
                        _delay_ms(10);
                }

	}

        return (0);
}
