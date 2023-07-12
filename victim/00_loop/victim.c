#include <avr/io.h>
#include <stdint.h>
#include <string.h>

#define UART_BAUD 9600
#define BLINK_DELAY_MS 10

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

void uart_int(int i) {
  char h = *((char *)&i + 1);
  char l = (char)i;
  if (h >> 15)
    uart_putchar('-');
  uart_putstr("0x");
  uart_hex(h & 0x7f);
  uart_hex(l);
}

void uart_uint(int i) {
  char h = *((char *)&i + 1);
  char l = (char)i;
  uart_putstr("0x");
  uart_hex(h);
  uart_hex(l);
}

int main(void) {
  // setup serial
  uart_init();

  uart_putstr("Booting...\r\n");

  // set pin 5 of PORTB for output
  DDRB |= _BV(DDB5);

  // set pin 5 high to turn led on */
  PORTB |= _BV(PORTB5);

  while (1) {
    int c = 0;
    for (int i = 0; i < 100; i++) {
      for (int j = 0; j < 100; j++) {
        c++;
      }
    }

    uart_putstr("c == ");
    uart_int(c);
    uart_putstr("\r\n");

    if (c != 10000)
      break;
  }
  uart_putstr("You win!\r\n");
}
