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
#include "animation.h"
#include "display.h"

void animation_init(animationContext *ctxt) {
	ctxt->animationLength = 0;
  ctxt->currentFrame = 0;
  ctxt->animationRunning = 0;
  ctxt->lastRunTime = 0;
  ctxt->myDuration = 0;
  ctxt->playOnce = 0;
}

void animation_load(animationContext *ctxt, animationFrame* frames, uint8_t numFrames) {
	animation_stop(ctxt);
	ctxt->animationArray = frames;
	ctxt->animationLength = numFrames;
	ctxt->currentFrame = 0;
}

void animation_play(animationContext *ctxt) {
	ctxt->animationRunning = 1;
  ctxt->playOnce = 0;
}

void animation_playOnce(animationContext *ctxt) {
  ctxt->animationRunning = 1;
  ctxt->playOnce = 1;
}

void animation_pause(animationContext *ctxt) {
	ctxt->animationRunning = 0;	
}

void animation_stop(animationContext *ctxt) {
	ctxt->animationRunning = 0;
	ctxt->currentFrame = 0;

	uint8_t blankFrame[5] = {0, 0, 0, 0, 0};
	display_setFrame(blankFrame);
	display_update();
}

uint8_t animation_isStopped(animationContext *ctxt) {
  return !(ctxt->animationRunning);
}

void animation_update(animationContext *ctxt) {
  uint8_t myFrame[5];

  if(ctxt->animationRunning) {
		if((millis() - (ctxt->lastRunTime)) > (ctxt->myDuration)) {
      ctxt->myDuration = pgm_read_byte(&((ctxt->animationArray)[ctxt->currentFrame].duration));
      myFrame[0] = pgm_read_byte(&((ctxt->animationArray)[ctxt->currentFrame].frame[0]));
      myFrame[1] = pgm_read_byte(&((ctxt->animationArray)[ctxt->currentFrame].frame[1]));
      myFrame[2] = pgm_read_byte(&((ctxt->animationArray)[ctxt->currentFrame].frame[2]));
      myFrame[3] = pgm_read_byte(&((ctxt->animationArray)[ctxt->currentFrame].frame[3]));
      myFrame[4] = pgm_read_byte(&((ctxt->animationArray)[ctxt->currentFrame].frame[4]));
			(ctxt->currentFrame)++;
			if((ctxt->currentFrame) >= (ctxt->animationLength)) {
				if(ctxt->playOnce) {
				  ctxt->animationRunning = 0;
				}
				ctxt->currentFrame = 0;
			}
			display_setFrame(myFrame);
      display_update();
			ctxt->lastRunTime = millis();
		}
	}
}
