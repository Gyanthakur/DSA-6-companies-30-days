/* https://leetcode.com/problems/repeated-dna-sequences/submissions/1143344955/ */

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>ans;
        int n = s.length();
        if(n<=10) return ans;
        unordered_map<string,int>m;
        for(int i=0;i<=n-10;i++)
        {
            string h = s.substr(i,10);
            m[h]++;
        }
        for(auto it:m)
        {
            if(it.second > 1)
                ans.push_back(it.first);
        }
        return ans;
    }
};