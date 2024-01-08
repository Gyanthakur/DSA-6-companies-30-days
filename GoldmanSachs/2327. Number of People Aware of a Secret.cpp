/*  */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int>v(3000,0);
        v[1] = 1;
        int mod = 1e9+7;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+delay;j<i+forget;j++)
            {
                v[j] = (v[j]+v[i])%mod;
            }
        }
        int x = 0;
        long long int ans = 0;
        while(forget--)
        {
            ans = (ans + v[n-x]) % mod;
            x++;
        }
        return ans;
    }
};