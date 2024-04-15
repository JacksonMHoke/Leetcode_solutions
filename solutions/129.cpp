// 129. Sum Root to Leaf Numbers
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
    int sumNumbers(TreeNode* root) {
        return recursion(root, 0);
    }
    
    int recursion (TreeNode* root, int sum) {
        if (!root) return 0;
        sum=sum*10+root->val;
        if (!root->right && !root->left) return sum;
        return recursion(root->left, sum)+recursion(root->right, sum);
    }
};