/**
 * Chapter: Digital I/0
 * Exercise E06 (based on E05):
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

#define DELAY_MAX       (700)
#define DELAY_MIN       (1)
#define FADE_IN         (0)
#define FADE_OUT        (1)

int
main(void)
{
	uint8_t fade_type = FADE_IN;            	// Start with fade-in
        uint16_t delay = DELAY_MIN;             	// Set delay start value

	/* --- setup --- */

        DDRB = 0b00000000;
	PORTB = 0b00000000;

	/* --- loop --- */

        while (1) {

		PORTB &= ~(1 << LED_RED);   		// Turn LED on (clear bit)
                _delay_loop_2(delay);

                PORTB |= (1 << LED_RED);    		// Turn LED off (set bit)
                _delay_loop_2(DELAY_MAX - delay);

                if (fade_type == FADE_IN) {
                        delay++;
                        if (delay >= DELAY_MAX - 1) {
                                fade_type = FADE_OUT;
                        }
                } else {
                        delay--;
                        if (delay <= DELAY_MIN) {
                                fade_type = FADE_IN;
                        }
                }

	}

        return (0);
}
