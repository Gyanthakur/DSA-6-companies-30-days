/* https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1 */


#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        vector<int>ans;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
        {
            m[arr[i]]++;
        }
        for(auto it : m)
        {
            if(it.second == 2)
            {
                ans.push_back(it.first);
                break;
            }
        }
        
        for(int i=1;i<=n;i++)
        {
            if(m.find(i) == m.end())
            {
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};