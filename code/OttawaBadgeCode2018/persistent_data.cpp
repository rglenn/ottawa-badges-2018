/*
    This file is part of OttawaBadges2015.

    OttawaBadges2015 is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OttawaBadges2015 is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <EEPROM.h>
#include "Arduino.h"
#include "persistent_data.h"

#define NUM_MAKERS 512
#define numMakersArray (NUM_MAKERS/8)

static uint8_t makersEncountered[numMakersArray];

static uint16_t numMakers;

#define MAKERS_ENCOUNTERED_ADDRESS 128
#define NUM_MAKERS_ADDRESS 192
#define NAME_STRING_ADDRESS 194
#define CHECK_VALUE_ADDRESS 212
#define CHECK_VALUE 0x4242

static char nameString[17] = "YOUR NAME HERE!!";

static uint8_t dummy;
#define DUMMY_ADDRESS 0

void persist_init() {
  // MAJOR TODO: Read everything from EEPROM if a check value is found in EEPROM, otherwise default to 0
  uint8_t i;
  for(i=0; i<numMakersArray; i++) {
    makersEncountered[i] = 0;
  }

  numMakers = 260;

  uint16_t checkValue;
  EEPROM.get(CHECK_VALUE_ADDRESS, checkValue);
  if(checkValue != CHECK_VALUE) {
    // initialize eeprom
    checkValue = CHECK_VALUE;
    EEPROM.put(CHECK_VALUE_ADDRESS, checkValue);
    EEPROM.put(NUM_MAKERS_ADDRESS, numMakers);
    EEPROM.put(MAKERS_ENCOUNTERED_ADDRESS, makersEncountered);
    EEPROM.put(NAME_STRING_ADDRESS, nameString);
    EEPROM.get(DUMMY_ADDRESS, dummy);
  } else {
    // read values from eeprom
    EEPROM.get(NUM_MAKERS_ADDRESS, numMakers);
    EEPROM.get(MAKERS_ENCOUNTERED_ADDRESS, makersEncountered);
    EEPROM.get(NAME_STRING_ADDRESS, nameString);
    EEPROM.get(DUMMY_ADDRESS, dummy);
  }
}

void persist_getNameString(char *buf) {
  memcpy(buf, nameString, 17);
}

void persist_setNameString(char *buf) {
  memcpy(nameString, buf, 17);
  EEPROM.put(NAME_STRING_ADDRESS, nameString);
  EEPROM.get(DUMMY_ADDRESS, dummy);
}

uint16_t persist_getMaxMakers() {
  return NUM_MAKERS;
}

#define MY_ADDRESS_FLASH 0x7FFE

uint16_t persist_getMakerID() {
  return pgm_read_word(MY_ADDRESS_FLASH);
}

uint16_t persist_getNumMakers() {
  return numMakers;
}

void persist_setNumMakers(uint16_t newNum) {
  newNum = (newNum & 0x01FF);

  if(numMakers != newNum) {
    numMakers = newNum;
    // Write to EEPROM on change
    EEPROM.put(NUM_MAKERS_ADDRESS, numMakers);
    EEPROM.get(DUMMY_ADDRESS, dummy);
  }
}

void persist_encounterMaker(uint16_t makerID) {
  makerID = (makerID & 0x01FF);

  uint8_t arraySlot, bitNum;
  arraySlot = makerID / 8;
  bitNum = makerID % 8;

  uint8_t scratch = makersEncountered[arraySlot];
  scratch |= (1 << bitNum);
  if(makersEncountered[arraySlot] != scratch) {
    makersEncountered[arraySlot] = scratch;
    // Write to EEPROM on change
    EEPROM.put(MAKERS_ENCOUNTERED_ADDRESS, makersEncountered);
    EEPROM.get(DUMMY_ADDRESS, dummy);
  }
}

uint8_t persist_haveEncounteredMaker(uint16_t makerID) {
  makerID = (makerID & 0x01FF);

  uint8_t arraySlot, bitNum;
  arraySlot = makerID / 8;
  bitNum = makerID % 8;

  uint8_t scratch = makersEncountered[arraySlot];
  if (scratch & (1 << bitNum)) {
    return 1;
  }
  return 0;
}

static const uint8_t oneBits[] = {0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};

static uint8_t countOnes(uint8_t x) {
  uint8_t results;
  results = oneBits[x&0x0f];
  results += oneBits[x>>4];
  return results;
}

uint16_t persist_getNumMakersEncountered() {
  uint16_t scratch = 0;
  
  for(uint8_t i = 0; i < numMakersArray; i++) {
    scratch += countOnes(makersEncountered[i]);
  }

  return scratch;
}

void persist_erase() {
  // initialize eeprom
  uint16_t checkValue = CHECK_VALUE;
  uint8_t i;
  for(i=0; i<numMakersArray; i++) {
    makersEncountered[i] = 0;
  }

  numMakers = 0;
  
  EEPROM.put(CHECK_VALUE_ADDRESS, checkValue);
  EEPROM.put(NUM_MAKERS_ADDRESS, numMakers);
  EEPROM.put(MAKERS_ENCOUNTERED_ADDRESS, makersEncountered);
  EEPROM.get(DUMMY_ADDRESS, dummy);
}

