#include <inttypes.h>
#include <iostream>
#include <limits.h>
#include <string>

template <typename dType> // Just for fun.
dType interpret_bits(uint8_t *ctx)
{
    static unsigned iter;

    dType realData = static_cast<dType>(*ctx);

    std::cout << "Original Value > " << realData << std::endl;


    std::cout << "Function Iter #" << iter << " | [ Output ] ";

    for (unsigned test = 8; test > 0; test--)
    {
        std::cout << (realData & 0x01 ? 1 : 0) << " ";
        realData = realData >> 1;
    }

    std::cout << std::endl << std::endl;

    iter++;
    return realData;
}

int main()
{
    // ! We're displaying from MSB to LSB.
    uint8_t sample_data = 0x6C;

    // 0. Display Data.
    interpret_bits<unsigned long long>(&sample_data);

    // 1. Bitshift to the Left. (Inversed)
    sample_data = sample_data << 1;
    interpret_bits<unsigned long long>(&sample_data);

    // 2. Bitshift to the Right. (Inversed)
    sample_data = sample_data >> 1;
    interpret_bits<unsigned long long>(&sample_data);

    // 3. Bitshift to the Left (Inversed) Twice?
    sample_data = sample_data >> 2;
    interpret_bits<unsigned long long>(&sample_data);

    // 4. How about we modify certain bit nth element (that is zero) to one?
    sample_data |= 1ULL << 6; // We assume that nth -1 we can do is the 2nd to the last.
    interpret_bits<unsigned long long>(&sample_data);

    // 5. Make 2 MSB Switch OFF, and Vise Versa from Last 3 Bits of LSB.
    sample_data ^= 1ULL << 0;
    sample_data ^= 1ULL << 1;
    sample_data ^= 1ULL << 5;
    sample_data ^= 1ULL << 6;
    sample_data ^= 1ULL << 7;
    interpret_bits<unsigned long long>(&sample_data);

    // 6. Inverse the Condition from the Above.
    // sample_data |= 1ULL << 6;
    // interpret_bits<unsigned long long>(&sample_data);
    return 0;
}