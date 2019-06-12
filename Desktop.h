#ifndef __DESKTOP_H_INCLUDED__
#define __DESKTOP_H_INCLUDED__

#include "Retruino.h"

/*
   The Desktop app is a simple GUI, that enables you to
   select different apps using the Retruino joystick
   and display.
*/
extern class Desktop: public App {

    const uint32_t BACKROUND_COLOR = 0x4d5bff;
    const uint32_t TEXT_COLOR = 0xffffff;
    const uint32_t ITEM_COLOR = 0xffffff;

    const uint8_t ITEM_HEIGHT = 20;
    const uint8_t START_Y = 30;
    const uint8_t TEXT_Y = 6;

    uint8_t itemsCount = 0;
    uint8_t selectedItem = 1;

    String getName();
    void setup();
    void loop();
    void drawMenu();
    void addItem(char text[]);

} desktop;

#endif
