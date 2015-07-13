/**
 * Copyright (c) 2015 by Lukasz Marcin Podkalicki <lukasz@podkalicki.com>
 */

#ifndef	_ATTINY_INTERRUPT_H_
#define	_ATTINY_INTERRUPT_H_

#include <avr/interrupt.h>
#include "attiny.h"

#define	PCINT_handler()		ISR(PCINT0_vect)

#define	PCINT0_enable() 	GIMSK |= (1<<PCIE); PCMSK |= (1<<PCINT0)
#define	PCINT1_enable() 	GIMSK |= (1<<PCIE); PCMSK |= (1<<PCINT1)
#define	PCINT2_enable() 	GIMSK |= (1<<PCIE); PCMSK |= (1<<PCINT2)
#define	PCINT3_enable() 	GIMSK |= (1<<PCIE); PCMSK |= (1<<PCINT3)
#define	PCINT4_enable() 	GIMSK |= (1<<PCIE); PCMSK |= (1<<PCINT4)
#define	PCINT5_enable() 	GIMSK |= (1<<PCIE); PCMSK |= (1<<PCINT5)

#endif	/* !_ATTINY_TIMER_H_ */
