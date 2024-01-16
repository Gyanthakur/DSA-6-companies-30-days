/* https://leetcode.com/problems/friends-of-appropriate-ages/ */

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        unordered_map<int,int>mpp;
        for(auto it: ages){
            mpp[it]++;
        }
        int ans=0;
        for(auto it1 : mpp){
            
            int temp =0;
            int age1=it1.first;
            int count1=it1.second;
            for(auto it2 : mpp)
            {
                int age2=it2.first;
                int count2=it2.second;
                if (age1 == age2) {
                    if (age2 > (age1 * 0.5 + 7)){
                        temp += (count1 - 1);
                    }
                } else {
                    bool flag = true;
                    if (age2 <= (age1 * 0.5 + 7)) flag = false;
                    if (age2 > age1) flag = false;
                    if (age1 < 100 && age2 > 100) flag = false;
                    
                    if (flag){
                        temp += count2;
                    }
                }
                
            }
            ans+=count1*temp;
        }
        return ans;
    }
};