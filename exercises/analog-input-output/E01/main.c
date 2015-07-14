/**
 * Chapter: Analog I/O
 * Exercise E01:
 * 1) use usb2uart-device and potentiometer
 * 2) connect usb2uart-device's GND to attiny-board's GND
 * 3) connect usb2uart-device's RXD to attiny-board's PB3
 * 4) connect usb2uart-device's TXD to attiny-board's PB4
 * 5) connect potentiometer PIN1 to attiny-board's VCC
 * 6) connect potentiometer PIN1 to attiny-board's PB2 (it is ADC1)
 * 7) connect potentiometer PIN3 to attiny-board's GND
 * 8) set registers DDRB (I/O selection) and PORTB (High/Low selection) - configure PB2 as INPUT with LOW state
 */

#include <avr/io.h>
#include <util/delay.h>
#include "attiny_debug.h"					// for "debug_init"
#include "attiny_utils.h"					// for "sbi" (set bit) and "cbi" (clear bit)

#define	POTENTIOMETR_PIN	PB0

int
main(void)
{
	uint8_t low, high;
	uint16_t value;

	/* --- setup --- */

	DDRB = 0b00000000;
	PORTB = 0b00000000;
	debug_init();						// Initalize debug (redirect standard I/O streams to UART)

	/* --- loop --- */

	printf("[ Analog I/O - E01 ]\n");

        while (1) {

		ADMUX = 1 << MUX0;                              // ADC selection (ADC1)

		sbi(ADCSRA, ADEN);				// Enable ADC
		sbi(ADCSRA, ADSC);				// Run single conversion

		while(bit_is_set(ADCSRA, ADSC));		// Wait untill conversion is done

        	low = ADCL;					// Read values from 8-bit registers, low byte
        	high = ADCH;					// and high byte

        	value = (high << 8) | low;			// Combine the two bytes and create one 16-bit value

		printf("value=%u\n", value);			// Send some bytes to usb2uart-device

		_delay_ms(1000);				// One second pause
	}

        return (0);
}
