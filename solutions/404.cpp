// 404. Sum of Left Leaves
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
    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root, -1);
    }

    int helper(TreeNode* root, int left) {
        if (!root) 
            return 0;
        if (!root->left && !root->right)
            return (left==1) ? root->val : 0;
        return helper(root->left, 1)+helper(root->right, 0);
    }
};