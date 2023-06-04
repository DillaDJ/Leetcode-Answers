#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "helper.cpp"

using namespace std;


vector<vector<string>> groupAnagrams_map_sort(vector<string>& strs) 
{
    unordered_map<string, vector<string>> matched_frequencies{};
    vector<vector<string>> out;

    for (int i{}; i < strs.size(); ++i)
    {
        unordered_map<char, int> frequency{};

        string sorted{ strs[i] };
        sort(sorted.begin(), sorted.end());
        
        matched_frequencies[sorted].push_back(strs[i]);
    }
    
    for (auto const& [key, val] : matched_frequencies)
        out.push_back(val);

    return out;
}


vector<vector<string>> groupAnagrams_map_freq(vector<string>& strs) {
    vector<unordered_map<char, int>> freq_array{};
    vector<vector<string>> anagram_groups{};
    
    for (const string& str : strs) {
        unordered_map<char, int> str_freq {};
        for (char c : str) str_freq[c] += 1;
        
        bool found{};

        for (int i{0}; i < freq_array.size(); ++i) {
            if (freq_array[i] == str_freq) {
                anagram_groups[i].push_back(str);
                found = true;
                break;
            }
        }

        if (!found) {
            anagram_groups.push_back(vector<string>{str});
            freq_array.push_back(str_freq);
        }
    }

    return anagram_groups;
}


int main()
{
    vector<string> a {"eat","tea","tan","ate","nat","bat"};
    vector<string> b {""};
    vector<string> c {"a"};
    vector<string> d {"eat","tea","tan","ate","nat","bat", "fat", "cat", "act", "aft", "taf", "eta"};

    cout << "~ Using Frequency Map ~\n\n";
    outputFunctionStats(groupAnagrams_map_freq, a);
    outputFunctionStats(groupAnagrams_map_freq, b);
    outputFunctionStats(groupAnagrams_map_freq, c);
    outputFunctionStats(groupAnagrams_map_freq, d);
    
    resetCases();
    
    cout << "~ Using Sort ~\n\n";
    outputFunctionStats(groupAnagrams_map_sort, a);
    outputFunctionStats(groupAnagrams_map_sort, b);
    outputFunctionStats(groupAnagrams_map_sort, c);
    outputFunctionStats(groupAnagrams_map_sort, d);

    return 0;
}