/**
 * Chapter: Watchdog
 * Exercise E00:
 * 1) use four-leds-shield
 * 2) connect four-leds-shield's LED1 to attiny-board's PB0
 * 3) connect four-leds-shield's GND to attiny-board's GND
 * 4) set registers DDRB (I/O selection) and PORTB (High/Low selection) - configure LED1 as OUTPUT with LOW state
 */

#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>

#define	LED_PIN		PB0

ISR(WDT_vect)
{
	uint8_t sreg;
	sreg = SREG;			// Make a copy of super register's value SREG
	cli();				// Clear interrupts
	PORTB ^= (1 << LED_PIN);	// Toggle LED on/off
	SREG = sreg;			// Restore SREG
}

int
main(void)
{

	/* --- setup --- */

	DDRB = 0b00000001;
	PORTB = 0b00000000;
	WDTCR = WDTO_500MS;		// Prescale watchodg to 128 (OSCILATOR/128; 0.5s; 65536 cycles)
	WDTCR |= (1<<WDE);		// Enable watchdog
	WDTCR |= (1<<WDIE);		// Enable watchdog's interrupt
        MCUSR &= ~(1<<WDRF);		// Clear the reset flag
	sei();				// Enable global interrupts

	/* --- loop --- */

        while (1);

	return (0);
}
