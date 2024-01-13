/* https://leetcode.com/problems/wiggle-sort-ii/description/ */


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int> q(nums.begin(), nums.end());
        for(int i=1; i<n; i+=2) {
            nums[i] = q.top();
            q.pop();
        }
        for(int i=0; i<n; i+=2) {
            nums[i] = q.top();
            q.pop();
        }
    }
};