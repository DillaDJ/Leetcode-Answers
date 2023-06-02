#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "helper.cpp"

using namespace std;


bool containsDuplicate_map(vector<int>& nums) {
    map<int, bool> map{};

    for(int i : nums) {
        if (map.count(i) == 0)
            map[i] = true;
        else
            return true;
    }

    return false;
}


bool containsDuplicate_sort(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            return true;
        }
    }

    return false;
}


int main() {
    vector<int> a { 1, 2, 3, 1 };
    vector<int> b { 1, 2, 3, 4 };
    vector<int> c { 1, 1, 1, 3, 3, 4, 3, 2, 4, 2 };

    cout << "~Using Map Method~\n\n";
    outputFunctionStats(containsDuplicate_map, a);
    outputFunctionStats(containsDuplicate_map, b);
    outputFunctionStats(containsDuplicate_map, c);

    resetCases();

    cout << "~Using Sort Method~\n\n";
    outputFunctionStats(containsDuplicate_sort, a);
    outputFunctionStats(containsDuplicate_sort, b);
    outputFunctionStats(containsDuplicate_sort, c);

    return 0;
}