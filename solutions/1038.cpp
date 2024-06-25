// 1038. Binary Search Tree to Greater Sum Tree
class Solution {
public:
    int helper(TreeNode* root, int gt=0) {
        root->val+=(root->right) ? helper(root->right, gt) : gt;
        return (root->left) ? helper(root->left, root->val) : root->val;
    }

    TreeNode* bstToGst(TreeNode* root) {
        return helper(root), root;
    }
};