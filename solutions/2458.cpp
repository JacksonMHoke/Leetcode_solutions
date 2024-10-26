// 2458. Height of Binary Tree After Subtree Removal Queries
class Solution {
public:
    int deepest(TreeNode* root, int level, vector<int>& deepestOnLevel, vector<int>& secondDeepestOnLevel, vector<int>& nodeDepth, vector<int>& nodeHeight) {
        if (!root)
            return 0;
        int maxDepth=1+max(deepest(root->left, level+1, deepestOnLevel, secondDeepestOnLevel, nodeDepth, nodeHeight),
                          deepest(root->right, level+1, deepestOnLevel, secondDeepestOnLevel, nodeDepth, nodeHeight));
        if (maxDepth>=deepestOnLevel[level]) {
            secondDeepestOnLevel[level]=deepestOnLevel[level];
            deepestOnLevel[level]=maxDepth;
        } else if (maxDepth>secondDeepestOnLevel[level]) {
            secondDeepestOnLevel[level]=maxDepth;
        }
        nodeHeight[root->val]=maxDepth;
        nodeDepth[root->val]=level;
        return maxDepth;
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> deepestOnLevel(100001);
        vector<int> secondDeepestOnLevel(100001);
        vector<int> nodeHeight(100001);
        vector<int> nodeDepth(100001);
        vector<int> rt;

        deepest(root, 0, deepestOnLevel, secondDeepestOnLevel, nodeDepth, nodeHeight);

        for (auto query : queries) {
            int level=nodeDepth[query];
            int height=nodeHeight[query];
            if (deepestOnLevel[level]==height)
                rt.push_back(level+secondDeepestOnLevel[level]-1);
            else
                rt.push_back(level+deepestOnLevel[level]-1);
        }
        return rt;
    }
};