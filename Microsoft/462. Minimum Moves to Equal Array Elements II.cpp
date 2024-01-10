/* https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/ */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        //  give TLE 
        int n = nums.size();
        int x = 0, cnt1=0;
        if(n%2==0)
            x = nums[n/2];
        else
            x = nums[n/2 + 1];
        for(int i=0;i<n/2;i++)
        {
            while(nums[i] != x)
            {
                nums[i]++;
                cnt1++;
            }
        }
        for(int i=n/2;i<n;i++)
        {
            while(nums[i] != x)
            {
                nums[i]--;
                cnt1++;
            }
        }
        return cnt1;
    }
};


class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int x = nums[nums.size()/2];
        int ans = 0;
        for(auto &i: nums){
            ans += abs(i-x);
        }
        return ans; 
    }
};