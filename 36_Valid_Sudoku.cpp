#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution 
{
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        // X
        for (vector<char> v : board)
        {
            unordered_map<char, bool> frequency{};

            for (char c : v)
            {
                if (c == '.') continue;
                if (frequency.count(c) > 0) return false;
                frequency[c] = true;
            }
        }

        // Y
        for (int x{}, y{}; x < 9;)
        {
            unordered_map<char, bool> frequency{};

            while (y < 9)
            {
                if (board[y][x] != '.')
                {
                    if (frequency.count(board[y][x]) > 0) return false;
                    else frequency[board[y][x]] = true;
                }

                y += 1;
            }

            x += + 1;
            y = 0;
        }


        // Block
        int block_x{}, block_y{}, block_i{};

        while (block_y < 3)
        {
            unordered_map<char, bool> frequency{};

            for (int x{(3 * block_x)}, y{(3 * block_y)}, i{}; i < 9; ++i)
            {
                if (board[y][x] != '.')
                {
                    if (frequency.count(board[y][x]) > 0) return false;
                    else frequency[board[y][x]] = true;
                }

                x = ((x + 1) % 3) + (3 * block_x);
                y = ((i + 1) / 3) + (3 * block_y);
            }

            block_x = ((block_x + 1) % 3);
            block_y = ((block_i + 1) / 3);
            block_i+= 1;
        }

        return true;
    }
};


int main()
{
    vector<vector<char>> in
    {{'.','.','4','.','.','.','6','3','.'}
    ,{'.','.','.','.','.','.','.','.','.'}
    ,{'5','.','.','.','.','.','.','9','.'}
    ,{'.','.','.','5','6','.','.','.','.'}
    ,{'4','.','3','.','.','.','.','.','1'}
    ,{'.','.','.','7','.','.','.','.','.'}
    ,{'.','.','.','5','.','.','.','.','.'}
    ,{'.','.','.','.','.','.','.','.','.'}
    ,{'.','.','.','.','.','.','.','.','.'}};

    cout << boolalpha << Solution{}.isValidSudoku(in) << '\n';
}