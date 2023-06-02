#include <iostream>
#include <algorithm>
#include <string>
#include "helper.cpp"

using namespace std;


bool isAnagram_sort(string& s, string& t) {
    if (s.length() != t.length()) return false;

    sort(s.begin(), s.begin());
    sort(t.begin(), t.end());

    for (int i = 0; i < s.length(); i++)
        if(s[i] != t[i]) return false;
            
    return true;
}


unordered_map<char, int> getCharFrequency(string& s) {
    unordered_map<char, int> frequency {};
    for (char c : s) frequency[c] += 1;
    return frequency;
}


bool isAnagram_map(string& s, string& t) {
    return (getCharFrequency(s) == getCharFrequency(t));
}


int main() 
{
    string rat {"rat"};
    string car {"car"};
    string anagram {"anagram"};
    string nagaram {"nagaram"};

    cout << "~Using Sort Method~\n\n";
    outputFunctionStats(isAnagram_sort, rat, car);
    outputFunctionStats(isAnagram_sort, anagram, nagaram);

    resetCases();

    cout << "~Using Map Method~\n\n";
    outputFunctionStats(isAnagram_map, rat, car);
    outputFunctionStats(isAnagram_map, anagram, nagaram);
 
    return 0;
}