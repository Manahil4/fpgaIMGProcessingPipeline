#include <stdint.h>
#include <stdio.h>
#include "pixel_buffer.h"

#define USE_FIXED_POINT

void convertToGrayscale() {
    for (size_t i = 0; i < K; i++) {
        uint8_t r = RGBimgbuffer.pxBFR[i].px[0];
        uint8_t g = RGBimgbuffer.pxBFR[i].px[1];
        uint8_t b = RGBimgbuffer.pxBFR[i].px[2];

#ifdef USE_FIXED_POINT
grayBuffer[i] = (77*r + 150*g + 29*b) >> 8;//Fixed point;shift right by 8 is divide by 256
#else
grayBuffer[i] = (uint8_t)(0.299*r + 0.587*g + 0.114*b);//floating point
#endif
}}