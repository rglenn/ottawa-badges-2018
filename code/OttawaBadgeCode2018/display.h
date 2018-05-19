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

#pragma once
#include "Arduino.h"

void display_init();
void display_setPixel(uint8_t x, uint8_t y, uint8_t val);
uint8_t display_getPixel(uint8_t x, uint8_t y);
void display_setFrame(uint8_t *frame);
void display_getFrame(uint8_t *frame);
void display_refresh();
void display_update();
void display_dump();
