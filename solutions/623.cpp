// 623. Add One Row to Tree
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth==1) {
            TreeNode* newNode = new TreeNode(val);
            newNode->left=root;
            root=newNode;
            return root;
        }
        helper(root, val, depth);
        return root;
    }

    void helper(TreeNode* root, int val, int depth) {
        if (!root) return;
        if (depth==2) {
            //inserting left
            TreeNode* newNode = new TreeNode(val);
            newNode->left=root->left;
            root->left=newNode;

            //inserting right
            newNode = new TreeNode(val);
            newNode->right=root->right;
            root->right=newNode;
            return;
        }
        helper(root->left, val, depth-1), helper(root->right, val, depth-1);
        return;
    }
};