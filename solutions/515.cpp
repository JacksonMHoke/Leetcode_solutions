// 515. Find Largest Value in Each Tree Row
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> rt;
        queue<pair<TreeNode*, int>> q;
        if (root)
            q.push({root, 0});
        while (!q.empty()) {
            TreeNode* top = q.front().first;
            int level = q.front().second;
            q.pop();

            if (level==rt.size())
                rt.push_back(INT_MIN);

            rt[level] = max(rt[level], top->val);
            if (top->left)
                q.push({top->left, level+1});
            if (top->right)
                q.push({top->right, level+1});
        }
        return rt;
    }
};