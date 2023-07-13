
victim.o: victim.c
	avr-gcc -O0 -DF_CPU=8000000UL -mmcu=atmega328p -c -o victim.o victim.c

trigger.o: trigger.c trigger.h
	avr-gcc -Os -DF_CPU=8000000UL -mmcu=atmega328p -c -o trigger.o trigger.c

uart.o: uart.c uart.h
	avr-gcc -Os -DF_CPU=8000000UL -mmcu=atmega328p -c -o uart.o uart.c

victim: victim.o uart.o trigger.o
	avr-gcc -mmcu=atmega328p victim.o uart.o trigger.o -o victim

victim.hex: victim
	avr-objcopy -O ihex -R .eeprom victim victim.hex

flash: victim.hex
	avrdude -F -V -c arduino -p m328p -P /dev/ttyUSB0 -b 57600 -U flash:w:victim.hex

clean:
	rm -f *.o
	rm -f *.hex
	rm -f victim

.PHONY: flash clean
