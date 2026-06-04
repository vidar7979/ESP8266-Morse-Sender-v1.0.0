# ESP8266 Morse Sender

Optical Morse communication transmitter written for ESP8266.

This project sends data using LED light pulses encoded as Morse code.

It is designed to work together with the MorseReader Raspberry Pi Pico receiver.

---

## Stable Release

Version:

v1.0.0

---

## Hardware

- ESP8266 development board
- LED transmitter

LED output:

D5

---

## Features

- Optical data transmission
- Morse encoded communication
- START frame marker
- STOP frame marker
- Data separators
- Alphabet support
- Number support
- Symbol support

Current transmitted data:

- IP address
- MAC address
- Subnet mask

---

## Communication

The ESP8266 sends a Morse frame:

START

DATA

STOP

Example:

192.168.1.2

00:1A:2B:3C:4D:5E

255.255.255.0

---

## Documentation

More information:

| Document | Description |
|---|---|
| docs/HARDWARE.md | Wiring information |
| docs/MORSE_PROTOCOL.md | Morse protocol |
| docs/BUILD.md | Build/upload guide |
| docs/ARCHITECTURE.md | Software structure |

---

## Development

Language:

C++

Framework:

Arduino / PlatformIO

---

## Author

Vidar Gudmundsson
