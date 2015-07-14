/**
 * Project: lfsrgen
 */

#include <attiny_digital.h>
#include <attiny_sleep.h>

#define	LED_PIN		PB0
#define SEED   		(12)

static uint16_t
prng_lfsr16(void)
{
        static uint16_t cnt16 = SEED;
        return (cnt16 = (cnt16 >> 1) ^ (-(cnt16 & 1) & 0xB400));
}

int
main(void)
{
	uint16_t value;

	/* --- setup --- */

	pin_mode(LED_PIN, OUTPUT);
	digital_write(LED_PIN, LOW);

	/* --- loop --- */

        while (1) {
		value = prng_lfsr16();

		if (value & 1)
			digital_write(LED_PIN, HIGH);
		else
			digital_write(LED_PIN, LOW);

		sleep(200);
	}

        return (0);
}
