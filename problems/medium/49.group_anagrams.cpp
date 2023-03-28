#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
/*
"""  [Problem]
        - Given an array of strings strs, group the anagrams together. 
          You can return the answer in any order.
        - Example : Input: strs = ["eat","tea","tan","ate","nat","bat"]
                    Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

    [Idea]
        - Use unordered map in C++ to store sorted unique word and its anagrams in the given list.
         (since it would be the same word if same group of anagrams get sorted)

    [Complexity]
        - Time : O( mlogm * n), where n=total number of words & m = max length among all strings.
        - Space : O(n * m), .
"""



*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> anagrams;

        for(string& s : strs){ // use auto& rather then auto to avoid unnecessary copy
            string sorted = s ;
            sort(sorted.begin(), sorted.end());
            mp[sorted].push_back(s);
        }
        anagrams.reserve(mp.size());//use vector.reserve() to avoid reallocate
        for(auto& p : mp){
            anagrams.push_back(move(p.second)); // use std::move() to steal vector from map
        }
        return anagrams;
    }
};