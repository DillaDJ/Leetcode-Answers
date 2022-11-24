#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    vector<int>& plusOne(vector<int>& digits) 
    { 
        int current_element {static_cast<int>(digits.size()) - 1};

        while (digits[current_element] == 9)
        {
            digits[current_element] = 0;
            --current_element;

            if (current_element == -1)
            {
                digits.push_back(0);
                current_element = 0;
                break;
            }           
        }
        
        ++digits[current_element];

        return digits;
    }
};


int main()
{
    vector<int> v1 {1, 2, 9, 4};

    vector<int> v {Solution{}.plusOne(v1)};

    for(int i : v)
    {
        cout << i << " ";
    }

    cout << endl;
}