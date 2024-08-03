/**
 * @file comparativeCountWithBuffer.cpp
 * @author Izaak Wolfgang White 
 * @brief kernel to compare to floas and return the amount that are equal
 * @date 2024-08-05
 */
//#include <iostream>
#include <cstdlib>

#define NTAPS 32

float output[NTAPS];
float input1[NTAPS]=
{
0,1,2,3,4,5,6,7,
8,9,10,11,12,13,14,15,
16,17,18,19,20,21,22,23,
24,25,26,27,28,29,30,31
};
float input2[NTAPS]=
{
0,1,2,3,4,5,6,7,
0,1,2,3,4,5,6,7,
10,10,10,10,10,10,10,10,
24,25,26,27,28,29,30,31
};


void kernel(float input1[], float output[], float input2[]);

int main() {
    kernel(input1, output, input2);
    // std::cout << output[0] << std::endl;
    return 0;
}

void kernel(float input1[], float output[], float input2[]) {
    int i;
    float count = 0;
    float *buffer = (float*)malloc(NTAPS * sizeof(float));

    if (buffer == NULL) { return; }

    for (i = 0; i < NTAPS; ++i) {
        buffer[i] = (input1[i] == input2[i]) ? 1.0f : 0.0f;
        count += buffer[i];
    }
    output[0] = count;

    free(buffer);
}
