#include <iostream>
#include <vector>
#include "helper.cpp"

using namespace std;


vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> lRunningProduct {};
    vector<int> rRunningProduct {};
    vector<int> products {};

    lRunningProduct.push_back(nums[0]);
    rRunningProduct.push_back(nums[nums.size() - 1]);
    
    for (int i{1}; i < nums.size(); ++i) {
        lRunningProduct.push_back(nums[i] * lRunningProduct[i - 1]);
        rRunningProduct.push_back(nums[nums.size() - 1 - i] * rRunningProduct[i - 1]);
    }
    
    products.push_back(rRunningProduct[nums.size() - 2]);
    for (int i{1}; i < nums.size() - 1; ++i) {
        products.push_back(lRunningProduct[i - 1] * rRunningProduct[nums.size() - 2 - i]);
    }
    products.push_back(lRunningProduct[nums.size() - 2]);

    return products;
}


int main() {
    vector<int> a { 1, 2, 3, 4 };
    vector<int> b { -1, 1, 0, -3, 3 };
    
    outputFunctionStats(productExceptSelf, a);
    outputFunctionStats(productExceptSelf, b);
    

    return 0;
}