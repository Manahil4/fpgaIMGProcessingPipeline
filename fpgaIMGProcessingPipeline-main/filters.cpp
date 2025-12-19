#include "pixel_buffer.h"
#include <stdint.h>
#include <stdlib.h>
#include <cmath>
namespace hardware {
    class Filter {
    public:
        virtual void apply() = 0; // Pure virtual function
    };

    class SmoothingFilter : public Filter {
    public:
        void apply() override {
            for (int y = 1; y < HEIGHT - 1; y++) {
                for (int x = 1; x < WIDTH - 1; x++) {
                    int sum = 0;
                    // 3x3 Average Box Filter
                    for (int ky = -1; ky <= 1; ky++) {
                        for (int kx = -1; kx <= 1; kx++) {
                            sum += grayBuffer[(y + ky) * WIDTH + (x + kx)];
                        }
                    }
                    resultBuffer[y * WIDTH + x] = sum / 9;
                }
            }
        }
    };

    class SobelEdgeFilter : public Filter {
    public:
        void apply() override {
            int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
            int Gy[3][3] = {{1, 2, 1}, {0, 0, 0}, {-1, -2, -1}};

            for (int y = 1; y < HEIGHT - 1; y++) {
                for (int x = 1; x < WIDTH - 1; x++) {
                    int sumX = 0, sumY = 0;
                    for (int ky = -1; ky <= 1; ky++) {
                        for (int kx = -1; kx <= 1; kx++) {
                            int val = grayBuffer[(y + ky) * WIDTH + (x + kx)];
                            sumX += val * Gx[ky + 1][kx + 1];
                            sumY += val * Gy[ky + 1][kx + 1];
                        }
                    }
                    int mag = (abs(sumX) + abs(sumY));
                    resultBuffer[y * WIDTH + x] = (mag > 255) ? 255 : mag;
                }
            }
        }
    };
}