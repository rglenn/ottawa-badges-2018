/*
    This file is part of OttawaBadges2016.

    OttawaBadges2016 is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OttawaBadges2016 is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with OttawaBadges2016.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "Arduino.h"
#include "display.h"

static volatile uint8_t frameBuffer[5] = {0, };
// Mapping on the following bytes:
// 7: Unused
// 6: Digital 10
// 5: Digital 9
// 4: Digital 8
// 3: Digital 6
// 2: Digital 5
// 1: Digital 4
// 0: Analog 3
static volatile uint8_t frame_port[40] = {0, }, frame_ddr[40] = {0, };
static volatile uint8_t currentLED = 0;
static const uint8_t numLEDs = 40;

void display_init() {
  pinMode(17, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void display_setPixel(uint8_t x, uint8_t y, uint8_t val) {
  if(x >= 8) return; // silently limits parameter to actual number of LEDs. so don't use imaginary LEDs.
  if(y >= 5) return;
  
  if(val) {
    frameBuffer[y] |= (1 << x);
  } else {
    frameBuffer[y] &= ~(1 << x);
  }
}

uint8_t display_getPixel(uint8_t x, uint8_t y) {
  if(x >= 8) return 255; // silently limits parameter to actual number of LEDs. so don't use imaginary LEDs.
  if(y >= 5) return 255;
  return (frameBuffer[y] & (1 << x));
}

void display_setFrame(uint8_t *frame) {
  frameBuffer[0] = frame[0];
  frameBuffer[1] = frame[1];
  frameBuffer[2] = frame[2];
  frameBuffer[3] = frame[3];
  frameBuffer[4] = frame[4];
}

void display_getFrame(uint8_t *frame) {
  frame[0] = frameBuffer[0];
  frame[1] = frameBuffer[1];
  frame[2] = frameBuffer[2];
  frame[3] = frameBuffer[3];
  frame[4] = frameBuffer[4];
}

void display_refresh() {
  uint8_t temp_portb = 0, temp_portc = 0, temp_portd = 0;
  uint8_t temp_ddrb = 0, temp_ddrc = 0, temp_ddrd = 0;

  if(currentLED >= numLEDs) {
    currentLED = 0;
  }

  temp_portb = frame_port[currentLED] >> 4;
  temp_ddrb = frame_ddr[currentLED] >> 4;
  temp_portc = (frame_port[currentLED] & 0x01) ? 0x08 : 0;
  temp_ddrc = (frame_ddr[currentLED] & 0x01) ? 0x08 : 0;
  temp_portd = (frame_port[currentLED] & 0x0e) << 3;
  temp_ddrd = (frame_ddr[currentLED] & 0x0e) << 3;

  DDRB &= 0xF8;
  DDRB |= temp_ddrb;
  DDRC &= 0xF7;
  DDRC |= temp_ddrc;
  DDRD &= 0x8F;
  DDRD |= temp_ddrd;

  PORTB &= 0xF8;
  PORTB |= temp_portb;
  PORTC &= 0xF7;
  PORTC |= temp_portc;
  PORTD &= 0x8F;
  PORTD |= temp_portd;

  currentLED++;
}

// LED array:
// LED1  LED6  LED11 LED16 LED21 LED26 LED31 LED36
// LED2  LED7  LED12 LED17 LED22 LED27 LED32 LED37
// LED3  LED8  LED13 LED18 LED23 LED28 LED33 LED38
// LED4  LED9  LED14 LED19 LED24 LED29 LED34 LED39
// LED5  LED10 LED15 LED20 LED25 LED30 LED35 LED40

static const PROGMEM uint8_t portDrive[40] = {0b00100000, 0b00000001, 0b00000010, 0b00000100, 0b00010000, 0b00100000, 0b01000000, 0b00000001,
                                              0b00010000, 0b01000000, 0b00000001, 0b00000010, 0b00000100, 0b00010000, 0b00100000, 0b01000000,
                                              0b00001000, 0b00010000, 0b01000000, 0b00000001, 0b00000010, 0b00001000, 0b00010000, 0b00100000,
                                              0b00000100, 0b00001000, 0b00100000, 0b01000000, 0b00000001, 0b00000010, 0b00001000, 0b00010000,
                                              0b00000010, 0b00000100, 0b00001000, 0b00100000, 0b01000000, 0b00000001, 0b00000100, 0b00001000};

static const PROGMEM uint8_t ddrDrive[40]  = {0b01100000, 0b01000001, 0b00100010, 0b00010100, 0b00011000, 0b00100100, 0b01000010, 0b00000011,
                                              0b01010000, 0b01100000, 0b00100001, 0b00010010, 0b00001100, 0b00010100, 0b00100010, 0b01000001,
                                              0b01001000, 0b00110000, 0b01010000, 0b00010001, 0b00001010, 0b00001100, 0b00010010, 0b00100001,
                                              0b01000100, 0b00101000, 0b00110000, 0b01001000, 0b00001001, 0b00000110, 0b00001010, 0b00010001,
                                              0b01000010, 0b00100100, 0b00011000, 0b00101000, 0b01000100, 0b00000101, 0b00000110, 0b00001001};

/*static const PROGMEM uint8_t anodeDrive[40] = {0b00100000, 0b00010000, 0b00001000, 0b00000100, 0b00000010, 0b00000001,
                                               0b01000000, 0b00010000, 0b00001000, 0b00000100, 0b00000010, 0b00000001,
                                               0b01000000, 0b00100000, 0b00001000, 0b00000100, 0b00000010, 0b00000001,
                                               0b01000000, 0b00100000, 0b00010000, 0b00000100, 0b00000010, 0b00000001,
                                               0b01000000, 0b00100000, 0b00010000, 0b00001000, 0b00000010, 0b00000001,
                                               0b01000000, 0b00100000, 0b00010000, 0b00001000, 0b00000100, 0b00000001,
                                               0b01000000, 0b00100000, 0b00010000, 0b00001000};
//static const PROGMEM uint8_t cathodeDrive[7] = {0b01000000, 0b00100000, 0b00010000, 0b00001000, 0b00000100, 0b00000010, 0b00000001};*/

void display_update() {
  uint8_t x, y, _anodeDrive;

  for(uint8_t i = 0; i < numLEDs; i++) {
    x = i % 8;
    y = i / 8;
    _anodeDrive = pgm_read_byte(portDrive + i);
    if(frameBuffer[y] & (1 << x)) {
      frame_port[i] = _anodeDrive;
    } else {
      frame_port[i] = 0;
    }
    //frame_ddr[i] = pgm_read_byte(cathodeDrive + (i / 6)) | _anodeDrive;
    frame_ddr[i] = pgm_read_byte(ddrDrive + i);
  }
}

void display_dump() {
  Serial.println("frame_port[] = {");
  for(uint8_t i = 0; i < numLEDs; i++) {
    Serial.print("0x");
    Serial.print(frame_port[i], HEX);
    if(i < (numLEDs - 1)) {
      Serial.print(", ");
    } else {
      Serial.println("};");
    }
  }
  Serial.println();

  Serial.println("frame_ddr[] = {");
  for(uint8_t i = 0; i < numLEDs; i++) {
    Serial.print("0x");
    Serial.print(frame_ddr[i], HEX);
    if(i < (numLEDs - 1)) {
      Serial.print(", ");
    } else {
      Serial.println("};");
    }
  }
}

