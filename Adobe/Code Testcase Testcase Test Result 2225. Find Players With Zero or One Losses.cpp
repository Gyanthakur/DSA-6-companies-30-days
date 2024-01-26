/* https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/ */


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>lost_matches;
        int n = matches.size();
        for(int i=0;i<n;i++)
        {
            int loss = matches[i][1];
            lost_matches[loss]++;
        }
        vector<int>notLost;
        vector<int>lostOnce;
        for(int i=0;i<n;i++)
        {
            int winner = matches[i][0];
            int loss = matches[i][1];

            if(lost_matches.find(winner) == lost_matches.end())
            {
                notLost.push_back(winner);
                lost_matches[winner] = 2;
            }
            if(lost_matches[loss] == 1)
            {
                lostOnce.push_back(loss);
            }
        }
        sort(begin(notLost),end(notLost));
        sort(begin(lostOnce),end(lostOnce));

        return {notLost,lostOnce};
    }
};