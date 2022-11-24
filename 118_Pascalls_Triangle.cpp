#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {        
        vector<vector<int>> result{};

        for (int i = 0; i < numRows; i++)
        {
            result.push_back(vector<int>{});

            for (int j = 0; j <= i; j++)
            {
                if (j - 1 < 0 || j >= result[i-1].size())
                    result[i].push_back(1);
                else
                    result[i].push_back(result[i-1][j - 1] + result[i-1][j]);
            }            
        }
        
        return result;
    }
};


int main()
{
    vector<vector<int>> triangle{Solution{}.generate(0)};

    for (vector<int> vi : triangle)
    {
        for (int i : vi)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}