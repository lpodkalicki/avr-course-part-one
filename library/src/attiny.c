/**
 * Copyright (c) 2015 by Lukasz Marcin Podkalicki <lukasz@podkalicki.com>
 */

#include <avr/interrupt.h>
#include "attiny.h"
#include "attiny_io.h"
#include "attiny_utils.h"

void
pin_mode(uint8_t pin, uint8_t mode)
{
	uint8_t sreg;

	if (mode == OUTPUT) {
		sreg = SREG;
		cli();
		sbi(DDRB, pin);
		SREG = sreg;
	} else { // mode == INPUT
		sreg = SREG;
		cli();
		cbi(DDRB, pin);
		SREG = sreg;
	}
}
