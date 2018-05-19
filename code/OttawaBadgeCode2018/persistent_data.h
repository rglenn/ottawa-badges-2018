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

#include "Arduino.h"

#pragma once

void persist_init();
uint16_t persist_getMaxMakers();
uint16_t persist_getMakerID();
uint16_t persist_getNumMakers();
void persist_setNumMakers(uint16_t newNum);
void persist_encounterMaker(uint16_t makerID);
uint8_t persist_haveEncounteredMaker(uint16_t makerID);
uint16_t persist_getNumMakersEncountered();
void persist_erase();
void persist_getNameString(char *buf);
void persist_setNameString(char *buf);

