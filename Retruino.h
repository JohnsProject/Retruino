#ifndef __RETRUINO_H_INCLUDED__
#define __RETRUINO_H_INCLUDED__

#include <TFT.h>
#include "Kernel.h"


/*
 * The Retruino library is used to access the components of the
 * Retruino in a hardware independet way, that means, if you
 * have another hardware just change the library and everything works.
 */
 

extern struct Input {

  const uint8_t JOY_X = 1;
  const uint8_t JOY_Y = 0;
  
  // Returns the position of the joystick in the given axis
  // Returns values between 0 and 1024
  uint16_t readJoystick(uint8_t joystick);
  // Returns the dir of the joystick in the given axis
  // Returns values between -1 and 1
  int8_t readJoystickDirection(uint8_t joystick);

} input;

extern struct Display {

  // display digital pin definition
  static const uint8_t CS = 10;
  static const uint8_t DC = 9;
  static const uint8_t RES = 8;

  // tft screen
  const TFT TFT_DISPLAY = TFT(CS, DC, RES);

  // tft screen constants
  uint8_t WIDTH;
  uint8_t HEIGHT;
  uint8_t HALF_WIDTH;
  uint8_t HALF_HEIGHT;
  
  // This method should be called before using the display
  // By default its called by the Desktop so no need to call anymore
  void setup();
  
  // Colors are always hex colors
  // I think the parameters rest are self reponding
  
  // Method used to draw a pixel
  void drawPixel (uint8_t x, uint8_t y, uint32_t color);
  // Method used to draw a line
  void drawLine (uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint32_t color);
  // Method used to draw the bounds of a rectangle
  void drawRect (uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint32_t color);
  // Method used to draw a filled rectangle
  void fillRect (uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint32_t color);
  // Method used to draw the bounds of a circle
  void drawCircle (uint8_t x, uint8_t y, uint8_t r, uint32_t color);
  // Method used to draw a filled circle
  void fillCircle (uint8_t x, uint8_t y, uint8_t r, uint32_t color);
  // Method used to draw text
  void drawText (uint8_t x, uint8_t y, char text[], uint32_t color, uint8_t size);
  // This method fills the display with the given color
  void fill (uint32_t color);

} display;

#endif
