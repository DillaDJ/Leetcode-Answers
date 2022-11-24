#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int climbStairs(int n) 
    {
        int prev{1};
        int curr{1};
        
        for (int i = 1; i < n; i++)
        {
            int next{prev + curr}; 
            
            prev = curr;
            curr = next;
        }
        
        return curr;
    }
};

int main() {
    int solution {Solution{}.climbStairs(5)};  

    cout << solution << endl;

    return 0;
}