/* https://leetcode.com/problems/trim-a-binary-search-tree/ */



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == nullptr) return nullptr;
        TreeNode* leftnode = trimBST(root->left,low,high);
        if(root->left!=leftnode)
            root->left= leftnode;
        TreeNode* rightNode = trimBST(root->right,low,high);
        if(root->right!=rightNode)
            root->right= rightNode;
        
        if(root->val>high || root->val<low)
        {
            return (root->left) ? root->left:root->right;
        }
        return root;
    }
};

