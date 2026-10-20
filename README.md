# Embedded-M03 ⚡

<p align="center">
  <img src="../Embedded-M00/assets/atmega328p.png" alt="ATmega328P board illustration" width="330" height="170" style="border-radius: 12px;" />
</p>

This module focuses on visual output and multi-color control on AVR targets. It introduces how to drive multiple GPIO lines to produce different LED states, including simple color sequences and periodic patterns.

The goal is to learn how a microcontroller can control several outputs at once and combine register-level logic with timing to generate dynamic effects.

## What you learn 🧠

This repository introduces the fundamentals of multiple-output control on AVR hardware:

- GPIO setup for multiple pins
- LED and RGB-style output control
- Sequential color or channel switching
- Timing-driven visual effects
- Register-level manipulation for distinct output states
- Basic firmware patterns for repetitive control loops

## Project setup 🛠️

This repository contains several small exercises under separate folders such as `ex00`, `ex01`, `ex02`, and `ex03`.

Each exercise is a compact firmware project focused on digital output patterns and timing for LEDs or color channels.

## Build commands 🔧

From the project root, you can compile an exercise with:

```bash
make -C ex00 hex
```

To flash the firmware to the board:

```bash
make -C ex00 flash
```

To build and flash in one step:

```bash
make -C ex00 all
```

To clean generated build files:

```bash
make -C ex00 clean
```

If you are inside the exercise folder itself, the commands are simply:

```bash
make hex
make flash
make all
make clean
```

## Required tools 🧰

You need the AVR toolchain installed on your machine:

- `avr-gcc`
- `avr-libc`
- `avr-objcopy`
- `avrdude`

On Debian/Ubuntu-based systems:

```bash
sudo apt update
sudo apt install gcc-avr avr-libc avrdude
```

## Hardware used 🖥️

This project targets an ATmega328P-based board, typically an Arduino-compatible board.

Typical hardware components:

- ATmega328P microcontroller
- RGB LED or multiple LEDs
- Output pins configured as digital GPIO
- USB programming interface / serial port

## Useful resources 📚

- ATmega328P datasheet: https://www.microchip.com/en-us/product/ATmega328P
- AVR libc documentation: https://www.nongnu.org/avr-libc/user-manual/
- AVR-GCC toolchain: https://gcc.gnu.org/wiki/avr-gcc
- avrdude documentation: https://github.com/avrdudes/avrdude

## Notes 📝

- Multi-color output is often implemented by driving separate channels with timed switching patterns.
- This module is ideal preparation for more advanced timing and PWM-based control.
- The code relies on direct register access, which makes the behavior easy to trace and debug at the hardware level.
