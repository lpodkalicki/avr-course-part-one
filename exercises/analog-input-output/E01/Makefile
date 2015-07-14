# --
# Copyright (c) 2015, Lukasz Marcin Podkalicki <lukasz@podkalicki.com>
# Makfile for exercise.
# --

include ../../exercise.in

EXERCISE_SRC = \
	main.c 

CFLAGS += -DUART_BAUDRATE=${UART_BAUDRATE} -DUART_RX_ENABLED -DUART_TX_ENABLED
	
all:
	${CC} ${CFLAGS} -o main.o ${EXERCISE_SRC} ${LIBRARY_SRC}
	${OBJCOPY} -j .text -j .data -O ihex main.o main.hex	

flash:
	${AVRDUDE} -p ${MCU} -c usbasp -U flash:w:main.hex:i -F -P usb

fuse:
	$(AVRDUDE)  -p ${MCU} -c usbasp -U hfuse:w:${FUSE_H}:m -U lfuse:w:${FUSE_L}:m

clean:
	rm -f *.o *.hex
