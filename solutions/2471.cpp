// 2471. Minimum Number of Operations to Sort a Binary Tree by Level
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> inOrder;
        inOrder.push(root);
        vector<int> sorted{root->val};
        unordered_map<int, TreeNode*> lvl;
        int swaps=0;
        while (!inOrder.empty()) {
            int sz=inOrder.size();
            vector<int> next;
            sort(sorted.begin(), sorted.end());
            for (int i=0; i<sz; ++i) {
                TreeNode* curr=inOrder.front();
                inOrder.pop();
                if (curr->left) {
                    next.push_back(curr->left->val);
                    lvl[curr->left->val]=curr->left;
                    inOrder.push(curr->left);
                }
                if (curr->right) {
                    next.push_back(curr->right->val);
                    lvl[curr->right->val]=curr->right;
                    inOrder.push(curr->right);
                }
                if (curr->val!=sorted[i]) {
                    swaps++;
                    lvl[sorted[i]]->val=curr->val;
                    lvl[curr->val]=lvl[sorted[i]];
                    lvl[sorted[i]]=curr;
                    curr->val=sorted[i];
                }
            }
            sorted=next;
        }
        return swaps;
    }
};