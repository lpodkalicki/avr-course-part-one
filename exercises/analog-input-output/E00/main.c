/**
 * Chapter: Analog I/O
 * Exercise E00:
 * 1) rgb-leds-shield
 * 2) connect usb2uart-device's GND to attiny-board's GND
 * 3) connect usb2uart-device's RXD to attiny-board's PB3
 * 4) connect usb2uart-device's TXD to attiny-board's PB4
 * 5) connect potentiometer PIN1 to attiny-board's VCC
 * 6) connect potentiometer PIN1 to attiny-board's PB2 (it is ADC1)
 * 7) connect potentiometer PIN3 to attiny-board's GND
 */

#include <avr/io.h>
#include <util/delay.h>

#define	LED_PIN		PB0

int
main(void)
{
	uint8_t i;

	/* --- Setup --- */

	DDRB = 0b00000001;
	PORTB = 0b00000000;
	TCCR0A = (1<<COM0A1)|(1<<WGM00); 	// Connect PWM to pin on timer 0 and channel A; set timer PWM mode
	TCCR0B = 1<<CS01;			// Set prescaler to 8 (CLK/8)

	/* --- Loop --- */

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
