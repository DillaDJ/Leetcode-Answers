#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if (prices.size() == 0) {
            return 0;
        }

        int profit = 0;
        int highest = 0;

        for (int i = prices.size() - 1; i >= 0; i--) {

            if (prices[i] > highest) {
                highest = prices[i];
            }
            else if (highest - prices[i] > profit) {
                profit = highest - prices[i];
            }

        }
        
        return profit;
    }
};


int main() {

    vector<int> in {2, 7, 3, 8, 1};

    cout << Solution().maxProfit(in) << endl;

    return 0;
}