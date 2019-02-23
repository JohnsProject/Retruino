#include "Retruino.h"

Input input;
Display display;

uint16_t Input::readJoystick(uint8_t joystick) {
  return analogRead(joystick);
}

int8_t Input::readJoystickDirection(uint8_t joystick) {
  int16_t pos = analogRead(joystick) - 500;
  if (pos > 300) return 1;
  if (pos < -300) return -1;
  return 0;
}


void Display::setup() {
  TFT_DISPLAY.begin();
  WIDTH = TFT_DISPLAY.width();
  HEIGHT = TFT_DISPLAY.height();
  HALF_WIDTH = WIDTH >> 1;
  HALF_HEIGHT = HEIGHT >> 1;
}

void Display::drawPixel (uint8_t x, uint8_t y, uint32_t color) {
  uint8_t red = color >> 16;
  uint8_t green = (color & 0x00ff00) >> 8;
  uint8_t blue = (color & 0x0000ff);
  TFT_DISPLAY.fill(blue, green, red);
  TFT_DISPLAY.point(x, y);
  TFT_DISPLAY.noFill();
}

void Display::drawLine (uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint32_t color) {
  uint8_t red = color >> 16;
  uint8_t green = (color & 0x00ff00) >> 8;
  uint8_t blue = (color & 0x0000ff);
  TFT_DISPLAY.stroke(blue, green, red);
  TFT_DISPLAY.line(x1, y1, x2, y2);
  TFT_DISPLAY.noStroke();
}

void Display::drawRect (uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint32_t color) {
  uint8_t red = color >> 16;
  uint8_t green = (color & 0x00ff00) >> 8;
  uint8_t blue = (color & 0x0000ff);
  TFT_DISPLAY.stroke(blue, green, red);
  TFT_DISPLAY.rect(x, y, w, h);
  TFT_DISPLAY.noStroke();
}

void Display::fillRect (uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint32_t color) {
  uint8_t red = color >> 16;
  uint8_t green = (color & 0x00ff00) >> 8;
  uint8_t blue = (color & 0x0000ff);
  TFT_DISPLAY.fill(blue, green, red);
  TFT_DISPLAY.rect(x, y, w, h);
  TFT_DISPLAY.noFill();
}

void Display::drawCircle (uint8_t x, uint8_t y, uint8_t r, uint32_t color) {
  uint8_t red = color >> 16;
  uint8_t green = (color & 0x00ff00) >> 8;
  uint8_t blue = (color & 0x0000ff);
  TFT_DISPLAY.stroke(blue, green, red);
  TFT_DISPLAY.circle(x, y, r);
  TFT_DISPLAY.noStroke();
}

void Display::fillCircle (uint8_t x, uint8_t y, uint8_t r, uint32_t color) {
  uint8_t red = color >> 16;
  uint8_t green = (color & 0x00ff00) >> 8;
  uint8_t blue = (color & 0x0000ff);
  TFT_DISPLAY.fill(blue, green, red);
  TFT_DISPLAY.circle(x, y, r);
  TFT_DISPLAY.noFill();
}

void Display::drawText (uint8_t x, uint8_t y, char text[], uint32_t color, uint8_t size) {
  uint8_t red = color >> 16;
  uint8_t green = (color & 0x00ff00) >> 8;
  uint8_t blue = (color & 0x0000ff);
  TFT_DISPLAY.stroke(blue, green, red);
  TFT_DISPLAY.setTextSize(size);
  TFT_DISPLAY.text(text, x, y);
  TFT_DISPLAY.noStroke();
}

void Display::fill (uint32_t color) {
  uint8_t red = color >> 16;
  uint8_t green = (color & 0x00ff00) >> 8;
  uint8_t blue = (color & 0x0000ff);
  TFT_DISPLAY.background(blue, green, red);
}
