# Retruino
Retruino is a tiny retro gaming console for the arduino, it's based on the ![Arduios](https://github.com/JohnsProject/Arduios), what enables you to upload multiple retro games once and play them.

## Creating your own games
It's very simple to create your own Retruino games. 

First you need to download the repository, with that done, open the ``Retruino.ino`` file with the Arduino IDE. Now add a new file to the sketch called ``TestGame.h``.

This game will be about moving a rectangle on the display using the joystick.

And here is how it looks like

```C++
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
```

To finish edit the ``Retruino.ino`` file, by adding ``#include "TestGame.h"`` and ``testGame`` to the apps array.

Congrats! you've just created your first Retruino app.
