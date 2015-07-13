/**
 * Exercise "Mrugacz-1"
 */

#include <avr/io.h>
#include <util/delay.h>

#define LED_PIN PB0                             // PB0 as LED pin

int
main(void)
{

        DDRB = 0b00000001;			// Set LED pin as output

        while (1) {                             // Infinity loop
                PORTB ^= 1 << LED_PIN;          // Toggle LED pin (HIGH/LOW)
                _delay_ms(500);                 // Wait 0.5 sec
        }

        return (0);
}
