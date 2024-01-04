#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = nums[0].length();
        vector<int>res;
        for(auto query : queries)
        {
            int k = query[0];
            int trim = query[1];
            priority_queue<pair<string,int>>pq;
            for(int i=0;i<n;i++)
            {
                string str = nums[i].substr(m-trim);
                pq.push({str,i});
                if(pq.size()>k)
                    pq.pop();
            }
            res.push_back(pq.top().second);
        }
        return res;
    }
};