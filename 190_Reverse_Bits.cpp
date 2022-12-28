#include <iostream>
#include <stdint.h>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t front_mask{ static_cast<uint32_t>(0b10000000000000000000000000000000) };
        uint32_t back_mask{ static_cast<uint32_t>(0b1) };
        uint32_t result{};

        while (front_mask) 
        {
            if (front_mask & n)
            {
                result |= back_mask;
            }

            front_mask >>= 1;
            back_mask <<= 1;
        }

        return result;
    }
};


int main()
{
    cout << Solution{}.reverseBits(static_cast<uint32_t>(0b00000010100101000001111010011100)) << endl;

    return 0;
}