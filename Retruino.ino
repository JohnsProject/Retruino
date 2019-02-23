/*
 * Retruino
 * by John´s Project
 *
 * Retruino is a tiny retro gaming console for the arduino,
 * it's based on the Arduios, what enables you to upload multiple
 * retro games once and play them.
 *
 * You can easily write an app by including "kernel.h",
 * extending and implementing the methods of the App class
 * and registering it in the apps array here.
 * (App class is in "kernel.h")
 *
 * You can access the Retruino hardware using the "Retruino.h"
 *
 * If you need docs just take a look into the '.h' files.
 * ----------------------------------------------------------
 * https://github.com/JohnsProject/Arduios
 * https://github.com/JohnsProject/Retruino
 * ----------------------------------------------------------
 *
 * This is the bootloader of the Arduios, it loads the kernel
 * and is the place where your apps should be registered.
 */

#include "Kernel.h"

#include "Desktop.h"
#include "Pong.h"  

// the kernel will call the first app in the array when its loaded
const App *apps[] = {
  &desktop,
  //&pong // uncomment to enable Pong
};

void setup() {
  kernel.setup(apps, sizeof(apps) / sizeof(App));
}

void loop() {
  kernel.loop();
}
