/* https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/ */

#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<bool, vector<int>> dfs(TreeNode* root, int &ans) {
        if (!root) return {true, {0, INT_MAX, INT_MIN}};
        auto left = dfs(root->left, ans);
        auto right = dfs(root->right, ans);
        
        if (!left.first || !right.first) return {false, {}};
        if (left.second[2] >= root->val || right.second[1] <= root->val) return {false, {}};
        
        int sum = root->val + left.second[0] + right.second[0];
        ans = max(ans, sum);
        int minimum = min(root->val, left.second[1]);
        int maximum = max(root->val, right.second[2]);
        return {true, {sum, minimum, maximum}};
    }
    
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};