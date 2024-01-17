/* https://leetcode.com/problems/top-k-frequent-words/description/ */


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string, int> m;
        vector<pair<int, string>> v;
        pair <int, string> p;
        vector<string> res;
        
        sort(words.begin(), words.end());
        
        for(int i=0; i<words.size(); i++)
        {
            if(m.find(words[i]) == m.end())
            {
                m[words[i]] = 1;
            }
            else
            {
                m[words[i]] += 1;
            }
        }
        
        for(int i=words.size()-1; i>=0; i--)
        {
            // cout << words[i] << " ";
            if(m[words[i]] != -1)
            {
                p = make_pair(m[words[i]], words[i]);
                v.push_back(p);
                m[words[i]] = -1;
            }
        }
        
        sort(v.begin(), v.end());
        vector<string> tmp;
        for(int i=v.size()-1; i>=0; i--)
        {
            if(tmp.size() == 0)
            {
                tmp.push_back(v[i].second);
            }
            else
            {
                if(v[i+1].first == v[i].first)
                {
                    tmp.push_back(v[i].second);
                }
                else
                {
                    sort(tmp.begin(), tmp.end());
                    for(int j=0; j<tmp.size(); j++)
                    {
                        res.push_back(tmp[j]);
                    }
                    tmp.clear();
                    tmp.push_back(v[i].second);
                }
            }
            if(k == 0) break;
        }
        
        if(tmp.size() != 0)
        {
            sort(tmp.begin(), tmp.end());
            for(int j=0; j<tmp.size(); j++)
            {
                res.push_back(tmp[j]);
            }
        }
        
        int size = res.size();
        for(int i=0; i<(size-k); i++) res.pop_back();
        
        return res;
    }
};