// 979. Distribute Coins in Binary Tree
class Solution {
public:
    int helper(TreeNode* root, int& rt) {
        if (!root)
            return 0;
        int r=helper(root->right, rt);
        int l=helper(root->left, rt);
        rt+=abs(r)+abs(l);
        return r+l+root->val-1;
    }
    int distributeCoins(TreeNode* root) {
        int rt=0;
        helper(root, rt);
        return rt;
    }
};