/*  https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/description/ */

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
long long int dp[4001][1001];
long long int count(int currVertex, int target, int k)
{
    long long mod = 1e9+7;
    if(k == 0 && currVertex == target)return 1;
    if(k == 0) return 0;
    if(dp[currVertex+1000][k] != -1)return dp[currVertex+1000][k];
    long long int a = count(currVertex+1, target, k-1);
    a+= count(currVertex-1, target, k-1);
    return dp[currVertex+1000][k] = a%mod;
}
    int numberOfWays(int startPos, int endPos, int k) {
        for(int i=0;i<=3001;i++)
        {
            for(int j=0;j<=k;j++)
            {
                dp[i][j] = -1;
            }
        }
        long long ans = count(startPos,endPos,k);
        return ans;
    }
};