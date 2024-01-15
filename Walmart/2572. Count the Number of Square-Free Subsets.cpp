/* https://leetcode.com/problems/count-the-number-of-square-free-subsets/description/ */



#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define md 1000000007
class Solution
{
public:
   int squareFreeSubsets(vector<int> &v)
   {
      ll n=v.size();
      ll a[10]={2,3,5,7,11,13,17,19,23,29};
      ll dp[n+1][1024];
      for(int i=0;i<1024;i++)
          dp[n][i]=1;
      for(ll i=n-1;i>=0;i--)
      {
          for(ll j=1023;j>=0;j--)
          {
              dp[i][j]=dp[i+1][j];
              bool ck=1;
              ll nj=j;
              ll ele=v[i];
              for(ll k=0;k<10;k++)
              {
                  while (ele%a[k]==0)
                  {
                      ele/=a[k];
                      if ((nj & 1<<k)>>k)
                      {
                          ck=0;
                          break;
                      }
                      else
                          nj=(nj | 1<<k);
                  }
              }
              if (ck)
              dp[i][j]=(dp[i][j]+dp[i+1][nj])%md;
          }
      }
      return (dp[0][0]-1+md)%md;
   }
};