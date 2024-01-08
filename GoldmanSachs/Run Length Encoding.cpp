/* https://www.geeksforgeeks.org/problems/run-length-encoding/1 */


#include<bits/stdc++.h>
using namespace std;

string encode(string src)
{     
  int length = src.length();
  int count=0;
  int i=0;
  string ans="";

  while(i<length){
      char a=src[i];
      ans+=a;
      while(src[i]==a){
          count++;
          i++;
      }
      ans+=to_string(count);
      count=0;
      
  }
  return ans;
  
}     