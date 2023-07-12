# FaultInjectionLab

## Quick Start
Clone this repo:

```
git clone https://github.com/ogianatiempo/FaultInjectionLab.git
git submodule update --init
cd pico-sdk
git submodule update --init
```

Install prerequisites:

```
sudo apt update
sudo apt install cmake gcc-arm-none-eabi libnewlib-arm-none-eabi build-essential gcc-avr avrdude
```

Build attacker code:

```
cd ../attacker
mkdir build
cd build
cmake ..
make
```

Then copy `power_glitch/power_glitch.uf2` to the Raspberry Pico, for example:

```
cp power_glitch/power_glitch.uf2 /media/octa/RPI-RP2/
```

Build the victim code:

```
cd ../../victim/00_loop/
make flash
```

## References and links

- Inspiration comes from [Hardware Power Glitch Attack (LiveOverflow)](https://www.youtube.com/watch?v=6Pf3pY3GxBM)
- Other ideas, victim's makefile and part of the victim's code comes from [Differential Fault Injection Against AES on Atmega328 (ROT256)](https://rot256.dev/post/glitch/)

Other resources and more info about fault injection in general:

- [The Hardware Hacking Handbook: Breaking Embedded Security with Hardware Attacks (Jasper van Woudenberg y Colin O'Flynn)](https://nostarch.com/hardwarehacking)
- [Fault Injection using Crowbars on Embedded Systems](https://eprint.iacr.org/2016/810.pdf)
- [An introduction to fault injection (NCC Group)](https://research.nccgroup.com/2021/07/07/an-introduction-to-fault-injection-part-1-3/)
