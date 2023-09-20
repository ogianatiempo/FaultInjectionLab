/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>

#include "hardware/clocks.h"
#include "hardware/pio.h"
#include "pico/stdlib.h"
#include "power_glitch.pio.h"

void power_glitch_setup(PIO pio, uint sm, uint offset, uint out_pin,
                        uint jmp_pin, uint freq);

int main() {
  setup_default_uart();

  // todo get free sm
  PIO pio = pio0;
  uint offset = pio_add_program(pio, &glitch_program);
  printf("Loaded program at %d\n", offset);

  power_glitch_setup(pio, 0, offset, 15, 16, 100);
}

void power_glitch_setup(PIO pio, uint sm, uint offset, uint out_pin,
                        uint jmp_pin, uint len) {
  glitch_program_init(pio, sm, offset, out_pin, jmp_pin);
  pio_sm_set_enabled(pio, sm, true);

  pio->txf[sm] = len;
}
