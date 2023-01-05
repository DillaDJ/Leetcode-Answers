#include <vector>
#include <iostream>
#include <cmath>

using namespace std;


class Solution 
{
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        
    }
};


int main()
{
    vector<vector<int>> mat{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    Solution{}.rotate(mat);

    for (vector<int> v : mat)
    {
        for (int i : v)
            cout << i << ' ';

        cout << '\n';
    }
    

    return 0;
}