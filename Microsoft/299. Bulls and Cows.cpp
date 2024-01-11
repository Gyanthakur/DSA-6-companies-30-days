/* https://leetcode.com/problems/bulls-and-cows/description/ */


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getHint(string secret, string guess)
    {
        int n=secret.size();
        int countb=0;
        int countc=0;
        string ans= "";
        for(int i=0;i<n;i++ )
        {
          if(secret[i]==guess[i])  //to count no of bulls
            { 
                countb++;
                guess[i]=-1;
                secret[i]=-1;
            }   
        }
        
        for(int i=0;i<n;i++)
        {
            if(secret.find(guess[i])!=-1 && guess[i]!=-1)  //to count no of cow
            {
                countc++;
                secret[secret.find(guess[i])]=-1;
            }
        }
         ans=to_string(countb)+"A"+to_string(countc)+"B";
        return ans;

    }
};