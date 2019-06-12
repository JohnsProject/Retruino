#include "Desktop.h"

Desktop desktop;

String Desktop::getName() {
  return F("Desktop");
}

void Desktop::setup() {
  display.setup();
  display.fill(BACKROUND_COLOR);
  display.drawText(10, display.HALF_HEIGHT - 20, "Retruino", TEXT_COLOR, 3);
  display.drawText(20, display.HALF_HEIGHT + 10, "by John's Project", TEXT_COLOR, 1);
  delay(1500);
  display.fill(BACKROUND_COLOR);
  drawMenu();
}

void Desktop::loop() {
  if (itemsCount > 0) {
    display.drawText(display.HALF_WIDTH + 50, ITEM_HEIGHT * (selectedItem-1) + TEXT_Y + START_Y, ">", BACKROUND_COLOR, 1);
    selectedItem += input.readJoystickDirection(input.JOY_Y);
    selectedItem = constrain(selectedItem, 1, itemsCount);
    display.drawText(display.HALF_WIDTH + 50, ITEM_HEIGHT * (selectedItem-1) + TEXT_Y + START_Y, ">", TEXT_COLOR, 1);
    if (input.readJoystickDirection(input.JOY_X) == 1) {
      kernel.loadApp(selectedItem);
    }
  }
}

void Desktop::drawMenu() {
  display.drawText(4, 8, "Retruino Apps", TEXT_COLOR, 2);
  for (uint8_t i = 1; i < kernel.registry.MAX_APPS; i++) {
    if(kernel.registry.apps[i] != NULL){
        String nameAsString = kernel.registry.apps[i]->getName();
        int nameLength = nameAsString.length() + 1;
        char text[nameLength];
        nameAsString.toCharArray(text, nameLength);
        addItem(text);
    }
   }
}

void Desktop::addItem(char text[]) {
  uint8_t y_jump = ITEM_HEIGHT * itemsCount + START_Y;
  display.drawRect(10, y_jump, display.WIDTH - 20, ITEM_HEIGHT - 2, ITEM_COLOR);
  display.drawText(20, y_jump + TEXT_Y, text, TEXT_COLOR, 1);
  itemsCount++;
}
