#include <stdio.h>
#include "pixel_buffer.h"
#include "filters.cpp" 

void loadFrame(const char* path);
void convertToGrayscale();
void saveGray(const char* path, uint8_t* buffer);
void printSmallBlock(uint8_t* buffer) {
    printf("\n--- Top Left 10x10 Pixels ---\n");
    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            printf("%3d ", buffer[y * WIDTH + x]);
        }
        printf("\n");
    }
}
int main() {
    const char* inputPath = "./rgbImg.rgb";
    
    // Stage 1: Load
    loadFrame(inputPath);

    // Stage 2: Grayscale
    convertToGrayscale();
    saveGray("./grayImg.gray", grayBuffer);
    // Stage 3: Hardware Filter Pipeline (Polymorphism)
    hardware::Filter* myFilter;
    
    // Run Smoothing (Blur)
    hardware::SmoothingFilter blur;
    myFilter = &blur;
    myFilter->apply();
    printSmallBlock(resultBuffer); 
    saveGray("./blurred.gray", resultBuffer);

    // Run Edge Detection
    hardware::SobelEdgeFilter sobel;
    myFilter = &sobel;
    myFilter->apply();
    printSmallBlock(resultBuffer);
    saveGray("./edges.gray", resultBuffer);

    printf("Full Hardware Pipeline Executed Successfully.\n");
    return 0;
}