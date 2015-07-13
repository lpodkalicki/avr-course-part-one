/**
 * Chapter: USART
 * Exercise E02:
 * 1) use usb2uart-device and rgb-leds-shield
 * 2) connect usb2uart-device's GND to attiny-board's GND
 * 3) connect usb2uart-device's RXD to attiny-board's PB3
 * 4) connect usb2uart-device's TXD to attiny-board's PB4
 * 5) connect rgb-leds-shield's LED_RED to attiny-board's PB0
 * 6) connect rgb-leds-shield's LED_GREEN to attiny-board's PB1
 * 7) connect rgb-leds-shield's LED_BLUE to attiny-board's PB2
 * 8) connect rgb-leds-shield's VCC to attiny-board's VCC
 * 9) set registers DDRB (I/O selection) and PORTB (High/Low selection) for LED_GREEN and LED_BLUE (note that LED_RED is already configured!)
 * 10) implement new commands hanlding to make this sketch work also for LED_GREEN ('G', 'g') and LED_BLUE ('B', 'b')
 */

#include <avr/io.h>
#include <util/delay.h>
#include "attiny_uart.h"

#define	LED_RED		PB0
#define	LED_GREEN	PB1
#define	LED_BLUE	PB2

int
main(void)
{
	char command;

	DDRB = 0b00000001;
	PORTB = 0b00000001;

	uart_puts("[ Exercise 02 ]\n");

        while (1) {

		command = uart_getc();

		switch(command) {
		case 'R':
			PORTB &= ~(1 << LED_RED);
			uart_puts("RED=1\n");
			break;
		case 'r':
			PORTB |= (1 << LED_RED);
                        uart_puts("RED=0\n");
                        break;
		default:
			uart_puts("Invalid command: ");
			uart_putc(command);
			uart_putc('\n');
			break;
		}
	}

        return (0);
}
