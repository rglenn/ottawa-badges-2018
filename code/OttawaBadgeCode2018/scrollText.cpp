#include "Arduino.h"
#include "display.h"
#include "font.h"

static char scrollString[32];
static uint8_t scrollStringLen = 0;
static uint16_t frameNum = 0;
static uint8_t letterNum = 0;
static uint8_t positionInLetter = 0;
static uint8_t letterBuffer[5];
static uint32_t lastScrollMillis;
static uint8_t framebuffer[5];

void scroll_reset() {
  scrollStringLen = 0;
  frameNum = 0;
  letterNum = 0;
  positionInLetter = 0;
  lastScrollMillis = 0;
  memset(framebuffer, 0, 5);
}

void scroll_setString(char *inStr, uint8_t len) {
  memset(scrollString, 0, 32);
  memcpy(scrollString, inStr, len);
  scrollStringLen = len;
}

void scroll_render() {
  uint8_t i;
  if((millis() - lastScrollMillis) > 200) {
    lastScrollMillis = millis();
    if(frameNum == 0) {
        memset(letterBuffer, 0, sizeof(letterBuffer));
        // get first letter
        letterNum = 0;
        positionInLetter = 0;
        for(i=0; i<5; i++) {
            letterBuffer[i] = pgm_read_byte(&(fontArray[scrollString[letterNum] - ' '][i]));
            letterBuffer[i] <<= (8 - fontWidth);
        }
    } else {
        // render the next letter onto the framebuffer
        for(i=0; i<5; i++) {
            framebuffer[i] >>= 1;
            if(letterBuffer[i] & 0x80) {
                framebuffer[i] |= 0x80;
            } else {
                framebuffer[i] &= 0x7f;
            }
            letterBuffer[i] <<= 1;
        }

        positionInLetter++;
    }

    frameNum++;
    if(positionInLetter > fontWidth) {
        positionInLetter = 0;
        letterNum++;
        if(letterNum >= (scrollStringLen + 4)) {
            frameNum = 0;
        } else if (letterNum >= scrollStringLen) {
            memset(letterBuffer, 0, sizeof(letterBuffer));
        } else {
            for(i=0; i<5; i++) {
                letterBuffer[i] = pgm_read_byte(&(fontArray[scrollString[letterNum] - ' '][i]));
                letterBuffer[i] <<= (8 - fontWidth);
            }
        }
    }

    display_setFrame(framebuffer);
    display_update();
  }
}

