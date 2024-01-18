/* https://leetcode.com/problems/sort-characters-by-frequency/ */

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        unordered_map<char,int>m;
        for(auto i:s)
        {
            m[i]++;
        }
        string ans = "";
        vector<pair<char,int>>v(m.begin(),m.end());
        sort(begin(v),end(v), [](pair<char,int>&a,pair<char,int>&b)
        {
            return a.second>b.second;
        });

        for(auto it:v)
        {
            if(it.second>1)
            {
                for(int i=0;i<it.second;i++)
                {
                    ans+=it.first;
                }
            }
            else
            {
                ans+=it.first;
            }
        }
        return ans;
    }
};