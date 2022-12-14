#include <iostream>

class Solution 
{
public:
    int mySqrt(int x) 
    {
        if(x == 0) return 0;

        int left{1}; 
        int right{x};
        int mid{};

        while(true) 
        {
            mid = left + (right - left) / 2;

            if (mid > x / mid)
                right = mid - 1;

            else
            {
                if (mid + 1 > x / (mid + 1))
                    return mid;
                
                left = mid + 1;
            }
        }
    }
};


int main()
{
    std::cout << Solution{}.mySqrt(20) << std::endl;

    return 0;
}