// 988. Smallest String Starting From Leaf
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
    void helper(TreeNode* root, string& smallest, string& curr) {
        if (!root) return;
        curr+=root->val+'a';
        bool isSmaller = lexicographical_compare(curr.rbegin(), curr.rend(), smallest.rbegin(), smallest.rend());

        if (!root->left && !root->right && isSmaller)
            smallest=string(curr);

        helper(root->left, smallest, curr), helper(root->right, smallest, curr);
        curr.pop_back();
        return;
    }

    string smallestFromLeaf(TreeNode* root) {
        string smallest = "|";
        string curr;
        helper(root, smallest, curr);
        reverse(smallest.begin(), smallest.end());
        return smallest;
    }
};