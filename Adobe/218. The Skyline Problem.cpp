/* https://leetcode.com/problems/the-skyline-problem/description/ */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // static bool sortin(pair<int,int>a,pair<int,int>b){
    //         if(a.first == b.first)
    //             return a.second<b.second;
    //         else
    //             return a.first<b.first;
    //     }
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>>res;
        vector<pair<int,int>>store;
        int n = buildings.size();
        for(int i=0;i<n;i++)
        {
            int height = buildings[i][2];
            int start = buildings[i][0];
            int end = buildings[i][1];

            store.push_back({start,-height});
            store.push_back({end,height});
            
        }
        sort(store.begin(),store.end(),[](pair<int,int>a,pair<int,int>b){
            if(a.first == b.first)
                return a.second<b.second;
            else
                return a.first<b.first;
        });
        int currHeight = 0;
        multiset<int>st;
        st.insert(0);

        for(auto x : store)
        {
            if(x.second<0)
            {
                st.insert(-1*x.second);

                if(currHeight != *st.rbegin())
                {
                    currHeight=*st.rbegin();

                    vector<int>temp={x.first,currHeight};
                    res.push_back(temp);
                }
            }
            else if(x.second>=0)
            {
                auto it = st.find(x.second);
                st.erase(it);

                if(*st.rbegin() != currHeight  )
                {
                    currHeight=*st.rbegin();

                    vector<int>temp={x.first,currHeight};
                    res.push_back(temp);
                }
            }
        }
        return res;
    }
};