#include <iostream>


using namespace std;


class Solution {
public:
    bool isSubsequence(string s, string t) {

        if (s == "" && t == "") {
            return true;
        }
        
        
        int s_pos = 0;

        for (int i = 0; i < t.length(); i++) {

            if (s[s_pos] == t[i]) {
                s_pos++;
            }

            if (s_pos == s.length()) {
                return true;
            }

        }

        return false;
    }
};


int main() {

    cout << Solution().isSubsequence("ae", "ahbgdc");

    return 0;
}