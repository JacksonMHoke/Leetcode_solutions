// 2641. Cousins in Binary Tree II
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> bfs;
        bfs.push(root);
        int currSum=0, nextSum=root->val;
        while (!bfs.empty()) {
            int sz=bfs.size();
            currSum=nextSum;
            nextSum=0;
            for (int i=0; i<sz; ++i) {
                TreeNode* curr=bfs.front();
                bfs.pop();

                curr->val=currSum-curr->val;
                int childSum=((curr->left) ? curr->left->val : 0)+((curr->right) ? curr->right->val : 0);

                if (curr->left) {
                    curr->left->val=childSum;
                    bfs.push(curr->left);
                }

                if (curr->right) {
                    curr->right->val=childSum;
                    bfs.push(curr->right);
                }
                nextSum+=childSum;
            }
        }
        return root;
    }
};