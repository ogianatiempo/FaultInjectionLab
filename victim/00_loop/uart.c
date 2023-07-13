#include "uart.h"
#include <avr/io.h>

#define UART_BAUD 9600

char HEX[] = {'0', '1', '2', '3', '4', '5', '6', '7',
              '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

void uart_init(void) {
  UBRR0 = (F_CPU / (8UL * UART_BAUD)) - 1;
  UCSR0B = _BV(TXEN0) | _BV(RXEN0);
}

void uart_putchar(char c) {
  loop_until_bit_is_set(UCSR0A, UDRE0);
  UDR0 = c;
}

void uart_putstr(char *s) {
  while (*s) {
    uart_putchar(*s);
    s++;
  }
}

void uart_hex(uint8_t c) {
  uart_putchar(HEX[c >> 4]);
  uart_putchar(HEX[c & 0xf]);
}

void uart_putint(int i) {
  char h = *((char *)&i + 1);
  char l = (char)i;
  if (h >> 15)
    uart_putchar('-');
  uart_putstr("0x");
  uart_hex(h & 0x7f);
  uart_hex(l);
}

void uart_putuint(int i) {
  char h = *((char *)&i + 1);
  char l = (char)i;
  uart_putstr("0x");
  uart_hex(h);
  uart_hex(l);
}
