#include "trigger.h"

void trigger_init() {
  // set pin 5 of PORTB for output
  DDRB |= _BV(DDB5);
}

void trigger_high() {
  // set pin 5 high to turn led on */
  PORTB |= _BV(PORTB5);
}

void trigger_low() {
  // set pin 5 high to turn led on */
  PORTB &= ~_BV(PORTB5);
}
