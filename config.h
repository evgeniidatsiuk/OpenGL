//
// Created by x on 12/2/19.
//

#ifndef OPENGLLINUXTEST_CONFIG_H
#define OPENGLLINUXTEST_CONFIG_H

// Force Redraw timer
#define TIMER 33.2          // 30 frame per second

// Window settings
#define WINTITLE "Arkanoid Laboratory Work"
const int WINWIDTH  = 800;
const int WINHEIGHT = 600;

// Wall settings
const int WALLWIDTH = 700;                          // Wall width
const int WALLHEIGHT = 180;                         // Wall height
const float WALLX = (WINWIDTH - WALLWIDTH) / 2.0f;  // Wall start point(x)
const float WALLY = WALLX + 40;                     // Wall start point(y)
const int WALLSPACE = 3;                            // Space between bricks
const int WALLCOLS = 15;                            // Wall columns count
const int WALLROWS = 10;                            // Wall rows count

// Pedal Settings
const float PEDALWIDTH = 150.0f;
const float PEDALHEIGHT = 12.0f;

// Ball settings
const float BALL_RADIUS = 10.0f;
const int CIRCLE_SEGMENTS = 50; // used in drawing ball

#endif