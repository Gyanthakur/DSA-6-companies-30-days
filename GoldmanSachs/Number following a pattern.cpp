/* https://www.geeksforgeeks.org/problems/number-following-a-pattern3126/1 */

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Function to print the minimum number following the given pattern
    string printMinNumberForPattern(string S) {
        int n = S.size();
        string result;
        stack<int> stk;
        for (int i = 0; i <= n; ++i) {
            stk.push(i + 1);
            if (i == n || S[i] == 'I') {
                while (!stk.empty()) {
                    result += to_string(stk.top());
                    stk.pop();
                }
            }
        }

        return result;
    }
};