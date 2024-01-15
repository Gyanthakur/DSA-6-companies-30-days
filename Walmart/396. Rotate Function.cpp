/* https://leetcode.com/problems/rotate-function/description/ */

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        int sum = 0, prod = 0;
        for(int i=0;i<n;i++)
        {
            prod += nums[i]*i;
            sum += nums[i];
        }
        maxi = prod;
        for(int i=1;i<n;i++)
        {
            int temp = prod + sum -nums[n-i] * n;
            prod = temp;
            maxi = max(maxi,prod);
        }
        return maxi;
    }
};