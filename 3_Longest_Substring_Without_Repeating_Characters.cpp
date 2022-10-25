#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char, bool> charmap { };
        queue<char> charqueue { };
        
        int no_repeats = 0;
        int result = 0;

        
        for (char c : s) {

            if (charmap[c]) {

                result = no_repeats > result ? no_repeats : result;

                while (charqueue.front() != c) {

                    charmap[charqueue.front()] = false;
                    charqueue.pop();
                    no_repeats--;
                
                }
                
                charqueue.pop();
                no_repeats--;
                
            }
            else {
            }

            charqueue.push(c);
            charmap[c] = true;
            no_repeats++;
        }

        result = no_repeats > result ? no_repeats : result;
        return result;
    }
};


int main() {

    cout << Solution().lengthOfLongestSubstring("") << endl;

    return 0;

}