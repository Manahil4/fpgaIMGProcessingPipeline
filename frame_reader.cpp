#include <stdio.h>
#include <stdint.h>
#include "pixel_buffer.h"

   


int loadFrame(const char* path) {

    uint8_t* img = new uint8_t[IMG_SIZE];

    // const char* path = "D:/ImgProcessingPipeline/rgbImg.rgb";
    FILE* f = fopen(path, "rb");
    if (!f) return -1;

    size_t bytes_read = fread(img, 1, IMG_SIZE, f);
    if(bytes_read != IMG_SIZE) {
        fclose(f);
        return -1;
    }
    fclose(f);
    printf("Pixel 0: R=%d G=%d B=%d\n",       RGBimgbuffer.pxBFR[0].px[0],       RGBimgbuffer.pxBFR[0].px[1],       RGBimgbuffer.pxBFR[0].px[2]);
    for (int pixelNo = 0; pixelNo < K; pixelNo++) {
        for (int ch = 0; ch < 3; ch++) {
            RGBimgbuffer.pxBFR[pixelNo].px[ch] = img[pixelNo * 3 + ch];
        }
    }
delete[] img;
    return 0;
}