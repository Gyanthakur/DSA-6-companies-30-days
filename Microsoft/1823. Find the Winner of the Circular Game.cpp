/* https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/ */

class Solution {
public:
    int solve(int n, int k)
    {
        if(n == 1)return 0;
        return (solve(n-1, k) + k)%n;
    }
    int findTheWinner(int n, int k) {
        
        int ans = solve(n,k);
        return ans+1;
    }
};