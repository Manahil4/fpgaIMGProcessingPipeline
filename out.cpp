#include <stdio.h>
#include <stdint.h>
#include "pixel_buffer.h"
void saveGray(const char* path, uint8_t* buffer) {
    FILE* f = fopen(path, "wb");
    if (!f) {
        printf("Failed to open file for writing\n");
        return;
    }
    fwrite(buffer, 1, K, f);
    fclose(f);
    printf("Grayscale saved to %s\n", path);
}
