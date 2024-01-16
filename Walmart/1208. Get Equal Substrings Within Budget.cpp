/* https://leetcode.com/problems/get-equal-substrings-within-budget/description/ */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        int ans_len = 0;

        int cost = 0;

        int start = 0;
        int end   = 0;

        //traversing on the string t and checking if the particular substring can be made equal
        
        while(end < (s.length()))
        {
            int diff = abs(t[end] - s[end]);

            while((start <= end) and (cost + diff) > maxCost)
            {
                cost = cost - abs(t[start] - s[start]);
                start++;
            }

            cost = cost + diff;
            ans_len = max(ans_len,(end - start + 1));
            end++;
        }
        return ans_len;
    }
};