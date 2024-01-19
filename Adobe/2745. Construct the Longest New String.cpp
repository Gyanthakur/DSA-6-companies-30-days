/* https://leetcode.com/problems/construct-the-longest-new-string/ */

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestString(int x, int y, int z) {
        if(x==y)
            return 2*z+4*x;
        else
            return 2*z + min(x,y)*4+2;
    }
};