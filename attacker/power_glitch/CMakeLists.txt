add_executable(power_glitch)

pico_enable_stdio_usb(power_glitch 1)
pico_enable_stdio_uart(power_glitch 0)

# by default the header is generated into the build dir
pico_generate_pio_header(power_glitch ${CMAKE_CURRENT_LIST_DIR}/power_glitch.pio)
# however, alternatively you can choose to generate it somewhere else (in this case in the source tree for check in)
#pico_generate_pio_header(power_glitch ${CMAKE_CURRENT_LIST_DIR}/power_glitch.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR})

target_sources(power_glitch PRIVATE power_glitch.c)

target_link_libraries(power_glitch PRIVATE pico_stdlib hardware_pio)
pico_add_extra_outputs(power_glitch)

