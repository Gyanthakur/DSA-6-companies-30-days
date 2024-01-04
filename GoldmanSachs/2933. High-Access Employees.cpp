#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findHighAccessEmployees(vector<vector<string>> &access_times)
    {
        unordered_map<string, vector<int>> m;
        for (auto &it : access_times)
        {
            int time = stoi(it[1]);
            m[it[0]].push_back(time);
        }
        for (auto &it : m)
        {
            sort(it.second.begin(), it.second.end());
        }
        vector<string> ans;
        for (auto &it : m)
        {
            vector<int> &time = it.second;
            for (int i = 2; i < time.size(); i++)
            {
                if (time[i] - time[i - 2] < 100)
                {
                    ans.push_back(it.first);
                    break;
                }
            }
        }
        return ans;
    }
};