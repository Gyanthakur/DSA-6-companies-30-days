/*  https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream/ */

#include<bits/stdc++.h>
using namespace std;
class DataStream {
    int val;
    int n;
    int cnt;
public:
    DataStream(int value, int k) {
        val = value;
        n=k;
        cnt=0;
    }
    
    bool consec(int num) {
        if(num == val)
            cnt++;
        else 
        {
            cnt = 0;
            return false;
        }
        if(cnt == n)
        {
            cnt = n-1;
            return true;
        }
        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */