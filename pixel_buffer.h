//shared memory for pixel buffers
#ifndef PIXEL_BUFFER_H
#define PIXEL_BUFFER_H
#include <stdint.h>
#define WIDTH 256
#define HEIGHT 256
#define CHANNELS 3
#define K (WIDTH * HEIGHT)
#define IMG_SIZE (K * CHANNELS)

struct pixel {
        uint8_t px[3];
    };
struct RGBbuffer {
  
    pixel pxBFR[K];
};

extern uint8_t grayBuffer[K];
extern uint8_t resultBuffer[K-3+1];
extern RGBbuffer RGBimgbuffer;

#endif //PIXEL_BUFFER_H