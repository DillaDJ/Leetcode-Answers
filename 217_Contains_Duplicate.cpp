#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, bool> map{};

        for(int i : nums)
        {
            if (map.count(i) == 0)
                map[i] = true;
            else
                return true;
        }

        return false;
    }
};


int main()
{
    vector<int> a{1, 2, 3, 4};
    cout << Solution{}.containsDuplicate(a) << endl;

    return 0;
}