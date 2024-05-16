// 2331. Evaluate Boolean Binary Tree
class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if (!root->left && !root->right)
            return root->val;
        return (root->val==2) ? (evaluateTree(root->left) || evaluateTree(root->right)) : (evaluateTree(root->left) && evaluateTree(root->right));
    }
};