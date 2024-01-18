/* https://leetcode.com/problems/word-break/description/ */

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool solve(int start, string s, unordered_set<string> &dict, vector<int> &dp) {
        if(start == s.size()) return true;
        if(dp[start] != -1) return dp[start];
        for(int i = start; i < s.size(); i++) {
            if(dict.count(s.substr(start, i - start + 1)) && solve(i+1, s, dict, dp)) {
                dp[start] = 1;
                return true;
            } 
        }
        return dp[start] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);
        return solve(0, s, dict, dp);    
    }
};