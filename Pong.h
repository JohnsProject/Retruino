#ifndef __PONG_H__
#define __PONG_H__

#include "Retruino.h"

/*
   Simple Pong app to show how the Retruino works.
*/
class Pong: public App {

    const uint32_t BLACK = 0x0;
    const uint32_t WHITE = 0xffffff;

    const uint8_t BAT_WIDTH = 4;
    const uint8_t BAT_HEIGHT = 14;
    const uint8_t HALF_BAT_WIDTH = BAT_WIDTH >> 1;
    const uint8_t HALF_BAT_HEIGHT = BAT_HEIGHT >> 1;

    const uint8_t BALL_RADIUS = 2;

    uint8_t bat1_x, bat1_y;
    uint8_t bat2_x, bat2_y;

    uint8_t points1 = 0, points2 = 0;

    uint8_t ball_x, ball_y;
    uint8_t dir_x = 1, dir_y = 1; // direction of the ball

    String getName() {
      return "Pong";
    }

    void setup() {
      // fill display black
      display.fill(BLACK);
      // set initial positions of objects
      bat1_x = 20;
      bat1_y = display.HALF_HEIGHT;
      bat2_x = display.WIDTH - 20;
      bat2_y = display.HALF_HEIGHT;
      ball_x = display.HALF_WIDTH;
      ball_y = display.HALF_HEIGHT;
    }

    void loop() {
      // update bat1
      drawBAT1(BLACK);
      bat1_y += input.readJoystickDirection(input.JOY_Y) << 1;
      drawBAT1(WHITE);
      //update bat2
      drawBAT2(BLACK);
      bat2_y = ball_y;
      drawBAT2(WHITE);
      //update ball
      drawBall(BLACK);
      moveBall();
      drawBall(WHITE);
      delay(10);
    }

    // updates the position of the ball based on collisions
    void moveBall() {
      if (ballCollision(ball_x, ball_y, bat1_x - HALF_BAT_WIDTH, bat1_y - HALF_BAT_HEIGHT, bat1_x + HALF_BAT_WIDTH, bat1_y + HALF_BAT_HEIGHT)) {
        dir_x = -dir_x;
      }
      if (ballCollision(ball_x, ball_y, bat2_x - HALF_BAT_WIDTH, bat2_y - HALF_BAT_HEIGHT, bat2_x + HALF_BAT_WIDTH, bat2_y + HALF_BAT_HEIGHT)) {
        dir_x = -dir_x;
      }
      if (ballCollision(ball_x, ball_y, 0, 0, display.WIDTH, 0)) {
        dir_y = -dir_y;
      }
      if (ballCollision(ball_x, ball_y, 0, display.HEIGHT, display.WIDTH, display.HEIGHT)) {
        dir_y = -dir_y;
      }
      if (ballCollision(ball_x, ball_y, 0, 0, 0, display.HEIGHT)) {
        dir_x = -dir_x;
        drawPoints(BLACK);
        points2 ++;
        drawPoints(WHITE);
      }
      if (ballCollision(ball_x, ball_y, display.WIDTH, 0, display.WIDTH, display.HEIGHT)) {
        dir_x = -dir_x;
        drawPoints(BLACK);
        points1 ++;
        drawPoints(WHITE);
      }
      if (ball_x == display.HALF_WIDTH) {
        drawNet(BLACK);
        drawNet(WHITE);
      }
      ball_x += dir_x;
      ball_y += dir_y;
    }

    // checks collision between ball and other object
    bool ballCollision(uint8_t ball_x, uint8_t ball_y, uint8_t obj_sx, uint8_t obj_sy, uint8_t obj_ex, uint8_t obj_ey) {
      if (((ball_x >= obj_sx) && (ball_x <= obj_ex))
          && ((ball_y >= obj_sy) && (ball_y <= obj_ey))) {
        return true;
      }
      return false;
    }

    // drawing methods //
    
    void drawBAT1(uint32_t color) {
      display.fillRect(bat1_x - HALF_BAT_WIDTH, bat1_y - HALF_BAT_HEIGHT, BAT_WIDTH, BAT_HEIGHT, color);
    }

    void drawBAT2(uint32_t color) {
      display.fillRect(bat2_x - HALF_BAT_WIDTH, bat2_y - HALF_BAT_HEIGHT, BAT_WIDTH, BAT_HEIGHT, color);
    }

    void drawBall(uint32_t color) {
      display.fillRect(ball_x - BALL_RADIUS, ball_y - BALL_RADIUS, BALL_RADIUS << 1, BALL_RADIUS << 1, color);
    }

    void drawNet(uint32_t color) {
      display.fillRect(display.HALF_WIDTH, 10, 1, display.HEIGHT - 10, color);
    }

    void drawPoints(uint32_t color) {
      char points1A[4];
      char points2A[4];
      String str1 = String(points1);
      String str2 = String(points2);
      str1.toCharArray(points1A, 4);
      str2.toCharArray(points2A, 4);
      display.drawText(display.HALF_WIDTH - 15, 10, points1A, color, 1);
      display.drawText(display.HALF_WIDTH + 5, 10, points2A, color, 1);
    }
} pong;

#endif 
