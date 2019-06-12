#ifndef __TESTGAME_H__
#define __TESTGAME_H__

#include "Retruino.h"

class TestGame: public App {

    const uint32_t BLACK = 0x0;
    const uint32_t WHITE = 0xffffff;

    uint8_t position_x;
    uint8_t position_y;
    const uint8_t SIZE = 5;

    String getName() {
      // return name of the game
      return "TestGame";
    }

    void setup() {
      // fill display black
      display.fill(BLACK);
      // set start position at the center of the display
      position_x = display.HALF_WIDTH;
      position_y = display.HALF_HEIGHT;
    }

    void loop() {
      // erase old rectangle
      display.fillRect(position_x, position_y, SIZE, SIZE, BLACK);
      // update position based on joystick position
      position_x += input.readJoystickDirection(input.JOY_X);
      position_y += input.readJoystickDirection(input.JOY_Y);
      // draw rectangle at new position
      display.fillRect(position_x, position_y, SIZE, SIZE, WHITE);
      delay(16);
    }

} testGame;

#endif
