// 1382. Balance a Binary Search Tree
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& vals) {
        if (!root)
            return;
        inorder(root->left, vals);
        vals.push_back(root->val);
        inorder(root->right, vals);
    }

    TreeNode* build_balanced(vector<int>& vals, int start, int end) {
        if (start>end)
            return nullptr;
        int mid=(start+end)/2;
        TreeNode* curr=new TreeNode(vals[mid]);
        curr->left=build_balanced(vals, start, mid-1);
        curr->right=build_balanced(vals, mid+1, end);
        return curr;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vals;
        inorder(root, vals);
        return build_balanced(vals, 0, vals.size()-1);
    }
};