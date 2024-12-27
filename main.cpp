#include <iostream>

#include "cubicbyte.h"

int main()
{
    uint8_t outputValue = 0, encoded = 0;
    CubicByte cubicByte;

    // Test X - Y
    for (size_t i = 0; i < 256; i++) {
        cubicByte.encode(i, encoded, false);
        cubicByte.decode(outputValue, encoded, false);
        std::cout << "Input Value = "  << i << "  Output Value = " << static_cast<int>(outputValue) << std::endl;
    }

    // Test Y - X
    for (size_t i = 0; i < 256; i++) {
        cubicByte.encode(i, encoded, true);
        cubicByte.decode(outputValue, encoded, true);
        std::cout << "Input Value = "  << i << "  Output Value = " << static_cast<int>(outputValue) << std::endl;
    }

    return 0;
}
