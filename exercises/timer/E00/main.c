/**
 * Chapter: Timer
 * Exercise E00:
 * 1) use four-leds-shield
 * 2) connect four-leds-shield's LED1 to attiny-board's PB0
 * 3) connect four-leds-shield's GND to attiny-board's GND
 * 4) set registers DDRB (I/O selection) and PORTB (High/Low selection) - configure LED1 as OUTPUT with LOW state
 */

#include <avr/io.h>
#include <avr/interrupt.h>

#define	LED_PIN		PB0

ISR(TIM0_OVF_vect)
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

	DDRB = 0b00000000;
	PORTB = 0b00000000;
	TCCR0B |= (1<<CS02)|(1<<CS00);	// Prescale timer to 1024 (CLK/1024)
	TIMSK |= 1 << TOIE0;		// Enable timer OVF (Overflow) interrupt
	sei();				// Enable global interrupts

	/* --- loop --- */

        while (1);

	return (0);
}
