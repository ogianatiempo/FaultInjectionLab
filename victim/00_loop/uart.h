#include <stdint.h>
#include <string.h>

void uart_init(void);
void uart_putchar(char c);
void uart_putstr(char *s);
void uart_hex(uint8_t c);
void uart_putint(int i);
void uart_putuint(int i);
void uart_putuint_dec(int u);