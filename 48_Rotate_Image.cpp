#include <vector>
#include <iostream>
#include <cmath>

using namespace std;


class Solution 
{
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int layer{};
        int size{static_cast<int>(matrix[0].size() - 1)};

        while (layer < (size + 1) / 2)
        {
            for (int i{}; i < size - (2 * layer); ++i)
            {
                int temp{matrix[layer][layer + i]};
                matrix[layer][layer + i]                = matrix[size - layer - i][layer];
                matrix[size - layer - i][layer]         = matrix[size - layer][size - layer - i];
                matrix[size - layer][size - layer - i]  = matrix[layer + i][size - layer];
                matrix[layer + i][size - layer]         = temp;
            }
            
            ++layer;
        } 
    }
};


int main()
{
    vector<vector<int>> mat{{5,1,7,9,11},{2,4,8,9,10},{13,3,4,6,7},{15,14,11,12,16},{3,4,5,6,7}};

    for (vector<int> v : mat)
    {
        for (int i : v)
            cout << i << ' ';

        cout << '\n';
    }
    cout << '\n';
    
    Solution{}.rotate(mat);

    for (vector<int> v : mat)
    {
        for (int i : v)
            cout << i << ' ';

        cout << '\n';
    }
    

    return 0;
}