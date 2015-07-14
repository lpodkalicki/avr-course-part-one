/**
 * Chapter: Serial Communication
 * Exercise E00:
 * 1) use usb2uart-device
 * 2) connect usb2uart-device's GND to attiny-board's GND
 * 3) connect usb2uart-device's RXD to attiny-board's PB3
 * 4) connect usb2uart-device's TXD to attiny-board's PB4
 */

#include <avr/io.h>
#include <util/delay.h>
#include "attiny_uart.h"

int
main(void)
{

	uart_puts("[ Exercise 00 ]\n");

        while (1) {
		uart_puts("Hello AVR Master!\n");
		_delay_ms(1000);
	}

        return (0);
}
