#include <iostream>
#include <string>
#include <cmath>

using namespace std;


class Solution {
    int ascii_to_int(char c)
    {
        return static_cast<int>(c) - 64;
    }

public:
    int titleToNumber(string columnTitle) {
        constexpr int base{26};
        int result{};

        for (int i = 0; i < columnTitle.size(); i++)
        {
            int current_digit{ascii_to_int(columnTitle[columnTitle.size() - 1 - i])};
            int current_base{static_cast<int>(pow(base, i))};

            result += current_base * current_digit;
        }
        
        return result;
    }
};


int main()
{
    cout << Solution{}.titleToNumber("ZY") << endl;

    return 0;
}