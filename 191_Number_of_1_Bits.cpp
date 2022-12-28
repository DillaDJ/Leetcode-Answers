#include <iostream>
#include <stdint.h>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t front_mask{ static_cast<uint32_t>(0b10000000000000000000000000000000) };
        int result{};
    
        while (front_mask) 
        {
            if (front_mask & n)
                ++result;

            front_mask >>= 1;
        }

        return result;
    }
};


int main()
{
    cout << Solution{}.hammingWeight(static_cast<uint32_t>(0b00000000000000000000000000001011)) << endl;

    return 0;
}