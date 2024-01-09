/* https://leetcode.com/problems/circle-and-rectangle-overlapping/description/ */
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
 public:
    bool checkOverlap(int r, int x, int y, int x1, int y1, int x2, int y2) 
    {
        for(int i=x1;i<=x2;i++)
        {
           for(int j=y1;j<=y2;j++)
           {
              int c1=i-x;
              int c2=j-y;
              if(c1*c1+c2*c2<=r*r)
                  return 1;
           }
        }
        return 0;
    }
};