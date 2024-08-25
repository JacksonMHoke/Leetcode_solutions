// 145. Binary Tree Postorder Traversal
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root)
            return {};

        stack<pair<TreeNode*, int>> s;
        vector<int> rt;
        s.push({root, 0});

        while (!s.empty()) {
            TreeNode* curr=s.top().first;
            int numVisits=s.top().second+1;

            s.pop();
            s.push({curr, numVisits});

            if (curr->left==curr->right || numVisits==3) {
                s.pop();
                rt.push_back(curr->val);
                continue;
            }
            
            if (curr->left && numVisits==1)
                s.push({curr->left, 0});
            if (curr->right && numVisits==2)
                s.push({curr->right, 0});
            
        }
        return rt;
    }
};