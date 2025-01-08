#include <iostream>
#include <bitset>

int main()
{
    // Create a bitset with a size of 32 bits
    std::bitset<32> bits{"10000000000000000000000000000000"};

    // Set individual bits
    bits[0]  = 1;
    bits[2]  = 1;
    bits[4]  = 1;
    bits[7]  = 1;
    bits.set(16);
    bits.set(17);

    // Display the binary representation
    std::cout << "Bitset: " << bits << std::endl;

    // Access specific bits
    bool t = bits.test(2);
    std::cout << "Bit at position 2 is set: " << t << std::endl;

    // Convert the bitset to an integer
    unsigned int i = bits.to_ulong();
    std::cout << "Integer: " << i << std::endl;

    // Bitset: 10000000000000110000000010010101
    // Bit at position 2 is set: 1
    // Integer: 2147680405

    return 0;
}
