/**
 * @file comparativeSum.cpp
 * @author Izaak Wolfgang White 
 * @brief kernel to compare to arrays and return the sum of all the elements that are equal
 * @date 2024-07-29
 */
//#include <iostream>

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

void kernel(float input1[], float output[],  float input2[]);

int main(){
  kernel(input1, output, input2);
  //std::cout<<output[0]<<std::endl;
  return 0;
}

void kernel(float input1[], float output[], float input2[]){
    int i;
    float sum = 0.0;
    for (i = 0; i < NTAPS; ++i) {
        if (input1[i] == input2[i]) {
            sum += input1[i]; //since values are equal add once
        }
    }
    output[0] = sum;
}
/*
* General Notes For Writing a Kernel for this CGRA:
* Works with Floats did not work with Ints
*/