#include <mram.h>
#include <stdint.h>
#include <stdio.h>

#define BUFFER_SIZE 128

//In mram
uint8_t __mram_noinit mram_array[BUFFER_SIZE];

int main() {
    //In wram
    __dma_aligned uint8_t input[BUFFER_SIZE];
    __dma_aligned uint8_t output[BUFFER_SIZE];

    //Copy data from mram to wram
    mram_read(mram_array, input, sizeof(input));

    printf("Input read!\n");

    //Do some calculations
    for(int i = 0; i < BUFFER_SIZE; i++) {
        output[i] = input[i] * 2;
    }

    //Copy data from wram to mram
    mram_write(output, mram_array, sizeof(output));
    printf("Output written!\n");

    return 0;
}