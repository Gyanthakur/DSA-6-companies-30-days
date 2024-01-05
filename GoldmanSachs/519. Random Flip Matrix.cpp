/* https://leetcode.com/problems/random-flip-matrix/?source=submission-ac */

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n,m;
    int i = 0,j = 0; // start with first row and first column
    Solution(int m, int n) {
        this->n = n;
        this->m = m;
    }
    
    vector<int> flip() {
        int I = i, J = j; // for returning purpose
        if(j + 1 < n) j++; // will iterate over columns till we can
        else if(i + 1 < m){ // will switch to next row and first col
            i++;
            j = 0;
        }
        else i = 0,j = 0; // will point back to first row and col
        // work as reset and continue to cycle again
        return {I,J};
    }
    
    void reset() {
        // no need of it, we have taken care of it in the flip() part
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */