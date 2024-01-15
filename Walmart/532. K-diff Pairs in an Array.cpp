/*  https://leetcode.com/problems/k-diff-pairs-in-an-array/description/ */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0,j=1,n = nums.size(),ans =0;
        while(j<n)
        {
            int diff = nums[j]-nums[i];
            if(diff == k)
            {
                ans++;
                int c1 = nums[i],c2=nums[j];
                while(i < n && c1 == nums[i])
                    i++;
                while(j<n && c2 == nums[j])
                    j++;
            }
            else if(diff>k)
                i++;
            else
                j++;
            if(i==j)
                j++;
        }
        return ans;
    }
};