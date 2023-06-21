#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include "helper.cpp"

using namespace std;


vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> frequencyMap{};
    vector<pair<int, int>> frequency{};
    vector<int> out{};

    for (int i{}; i < nums.size(); i++)
        ++frequencyMap[nums[i]];
    
    for (int i{}; auto const& [key, val] : frequencyMap)
        frequency.push_back(pair<int, int>{key, val});

    sort(frequency.begin(), frequency.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    });

    for (int i{}; i < k; i++)
        out.push_back(frequency[i].first);    

    return out;
}


vector<int> topKFrequent_bucket_sort(vector<int>& nums, int k) {
    unordered_map<int, int> frequencyMap{};
    vector<vector<int>> frequency{};
    vector<int> out{};

    for (int i{}; i < nums.size(); ++i) {
        frequency.push_back(vector<int>{});
        ++frequencyMap[nums[i]];
    }
    frequency.push_back(vector<int>{});
    
    // Place nums in 'bucket' at idx corresponding to frequency 
    for (int i{}; auto const& [key, val] : frequencyMap)
        frequency[val].push_back(key);

    for (int i{static_cast<int>(frequency.size()) - 1}, n{}; i >= 0; --i)
    {
        for (int j{}; j < frequency[i].size(); ++j, ++n)
        {
            out.push_back(frequency[i][j]);
            if (n >= k - 1) return out;
        }
    }

    return out;   
}


int main() {
    vector<int> a { 1, 1, 1, 2, 2, 3 };
    vector<int> b { 1 };
    vector<int> c { 4, 1, -1, 2, -1, 2, 3 };
    vector<int> d {5,9,2,2,6,8,4,6,6,9,4,2,1,5,6,8,1,3,2,3,2,4,4,3,10,7,1,1,10,2,1,3,6,1,9,2,7,1,5,2,2,3,2,2,3,6,6,9,5,3,2,5,7,4,1,10,7,9,1,9,4,1,4,6,8,9,8,7,10,8,9,10,6,2,9,4,4,10,7,7,7,7,6,6,6,10,7,10,9,8,3,1,2,2,1,9,3,9,10,7,6,6,9,4,2,1,5,6,8,1,3,2,3,2,4,4,3,10,7,1,1,10,2,1,3,6,1,9,2,7,1,5,2,2,3,2,2,3,6,6,9,5,3,2,5,7,4,1,10,7,9,1,9,4,1,4,6,8,9,8,7,10,8,9,10,6,2,9,4,4,10};

    outputFunctionStats(topKFrequent, a, 2);
    outputFunctionStats(topKFrequent, b, 1);
    outputFunctionStats(topKFrequent, c, 2);
    outputFunctionStats(topKFrequent, d, 5);

    resetCases();

    cout << "~ Using Bucket Sort ~\n\n";
    outputFunctionStats(topKFrequent_bucket_sort, a, 2);
    outputFunctionStats(topKFrequent_bucket_sort, b, 1);
    outputFunctionStats(topKFrequent_bucket_sort, c, 2);
    outputFunctionStats(topKFrequent_bucket_sort, d, 5);

    return 0;
}