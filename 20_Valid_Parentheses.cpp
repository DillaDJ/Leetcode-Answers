#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;


class Solution {
public:
    bool isValid(string s) {
        
        stack<char> bracket_stack {};

        unordered_map<char, char> bracket_map {
            { ')', '(' },
            { ']', '[' },
            { '}', '{' },
            { '>', '<' }
        };

        for (char c : s) {

            if (bracket_map.count(c) > 0) {

                char bracket_type = bracket_map[c];

                if (bracket_stack.empty() or bracket_stack.top() != bracket_type) {
                    return false;
                }

                bracket_stack.pop();
            }
            else {

                bracket_stack.push(c);

            }
        }
        
        return bracket_stack.empty();
    }
};


int main() {

    string in { "" };

    cout << Solution().isValid(in) << endl;

    return 0;
}