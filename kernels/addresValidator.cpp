/**
 * @file addresValidator.cpp
 * @author Izaak Wolfgang White
 * @brief Simple boolean checker to validate addresses
 * Goal is to simulate a streamed address checker by using pointers
 * @date 2024-08-03
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <cstdlib>

#define SIZE 32

bool isValidAccess(float address, float startAddress, float endAddress)
{
    return (address >= startAddress && address <= endAddress);
}

extern "C" float validateAddress(float address)
{
    float startAddress = 0x10000;
    float endAddress = 0x11000;
    return isValidAccess(address, startAddress, endAddress) ? 1.0f : 0.0f;
}

void kernel(float *input[], float *output[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        *output[i] = validateAddress(*input[i]);
    }
}

float *addresses[SIZE];
float addressValues[SIZE] = {
    0x10000, 0x11000, 0x12000, 0x10001,
    0x10002, 0x10003, 0x10004, 0x10005,
    0x10006, 0x10007, 0x10008, 0x10009,
    0x1000A, 0x1000B, 0x1000C, 0x1000D,
    0x1000E, 0x1000F, 0x10100, 0x10200,
    0x10300, 0x10400, 0x10500, 0x10600,
    0x10700, 0x10800, 0x10900, 0x10A00,
    0x10B00, 0x10C00, 0x10D00, 0x10E00};

float *output[SIZE];

int main()
{
    //Assign Address Values
    for (int i = 0; i < SIZE; ++i) {
        addresses[i] = &addressValues[i];
        output[i] = (float*)malloc(sizeof(float));
    }

    kernel(addresses, output, SIZE);

    for (int i = 0; i < SIZE; ++i) {
       /* std::cout << "Address " << std::hex << *addresses[i] << " is "
                  << (*output[i] == 1.0f ? "valid" : "invalid") << std::endl;*/
        free(output[i]);
    }

    return 0;
}