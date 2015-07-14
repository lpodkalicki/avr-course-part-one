/**
 * Project: blinky
 */

#include <attiny_digital.h>
#include <attiny_sleep.h>

#define	LED_PIN		PB0

int
main(void)
{

	/* --- setup --- */

	pin_mode(LED_PIN, OUTPUT);
	digital_write(LED_PIN, LOW);

	/* --- loop --- */

        while (1) {
		digital_toggle(LED_PIN);
		sleep(1000);
	}

        return (0);
}
