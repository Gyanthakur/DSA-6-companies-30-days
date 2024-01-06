/*  https://leetcode.com/problems/k-divisible-elements-subarrays/description/ */


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>>s;
        for(int i = 0; i < nums.size(); i++){
            vector<int> arr;
            int count = 0;
            for(int j = i; j >= 0; j--){
                arr.push_back(nums[j]);
                if(nums[j]%p == 0){
                    count++;
                }
                if(count <= k){
                    s.insert(arr);
                }else{
                    break;
                }
            }
        }
        return s.size();
    }
};