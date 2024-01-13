/* https://leetcode.com/problems/wiggle-sort-ii/description/ */


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n = nums.size();
        vector<int>v(n);
        int j = n-1;
        for(int i=1;i<n;i+=2)
        {
            v[i] = nums[j--];
        }
        for(int i = 0;i<n-1;i+=2)
        {
            v[i] = nums[j--];
        }
        for(int i=0 ; i<n;i++)
        {
            nums[i] = v[i];
        }
    }
};