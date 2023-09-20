#include "trigger.h"
#include "uart.h"

int main(void) {
  // setup serial
  uart_init();
  // setup trigger
  trigger_init();

  uart_putstr("Booting...\r\n");

  trigger_high();

  while (1) {
    int c = 0;
    for (int i = 0; i < 100; i++) {
      for (int j = 0; j < 100; j++) {
        c++;
      }
    }

    uart_putstr("c == ");
    uart_putuint_dec(c);
    uart_putstr("\r\n");

    if (c != 10000)
      break;
  }
  uart_putstr("You win!\r\n");
}
