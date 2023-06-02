#include <iostream>
#include <unordered_map>
#include <vector>
#include "helper.cpp"

using namespace std;


vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> index_table {};

    for (int i = 0; i < nums.size(); i++) {
        int remainder { target - nums[i] };

        if (index_table.count(remainder) > 0)
            return vector<int> { index_table[remainder], i };
        else
            index_table[nums[i]] = i;
    }

    return vector<int> { -1, -1 };
}

int main() {
    vector<int> a {2, 7, 11, 15};
    vector<int> b {3, 2, 4};
    vector<int> c {3, 3};

    cout << "~Using Map Method~\n\n";
    outputFunctionStats(twoSum, a, 9);
    outputFunctionStats(twoSum, b, 6);
    outputFunctionStats(twoSum, c, 6);

    return 0;
}