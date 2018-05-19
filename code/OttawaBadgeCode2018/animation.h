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

typedef struct {
  uint8_t frame[5];
  uint8_t duration;
} animationFrame;

typedef struct {
  uint8_t animationLength = 0;
  uint8_t currentFrame = 0;
  uint8_t animationRunning = 0;
  uint8_t myDuration = 0;
  uint8_t playOnce = 0;
  uint32_t lastRunTime = 0;
  animationFrame *animationArray;
} animationContext;

void animation_init(animationContext *ctxt);
void animation_load(animationContext *ctxt, animationFrame* frames, uint8_t numFrames);
void animation_play(animationContext *ctxt);
void animation_playOnce(animationContext *ctxt);
void animation_pause(animationContext *ctxt);
void animation_stop(animationContext *ctxt);
uint8_t animation_isStopped(animationContext *ctxt);
void animation_update(animationContext *ctxt);
