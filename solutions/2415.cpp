// 2415. Reverse Odd Levels of Binary Tree
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> bfs;
        stack<int> vals;
        bfs.push(root);
        int level=0;
        while (!bfs.empty()) {
            int sz=bfs.size();
            stack<int> next;
            while (sz--) {
                TreeNode* curr=bfs.front();
                bfs.pop();
                if (level%2==1) {
                    curr->val=vals.top();
                    vals.pop();
                }
                if (curr->left==curr->right)
                    continue;
                next.push(curr->left->val);
                next.push(curr->right->val);
                bfs.push(curr->left);
                bfs.push(curr->right);
            }
            level++;
            vals=next;
        }
        return root;
    }
};