/*  https://leetcode.com/problems/count-the-number-of-incremovable-subarrays-i/description/ */
#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool isIncreasingSubArr(vector<int>& nums, int s, int e)
    {
        int prev = 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(i >= s && i <= e)
                continue;
            if(nums[i] <= prev)
                return false;
            prev = nums[i];
        }
        return true;

    }
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            for(int j = i; j< n; j++)
            {
                if(isIncreasingSubArr(nums,i,j))
                    cnt++;
            }
        }
        return cnt;
    }
};