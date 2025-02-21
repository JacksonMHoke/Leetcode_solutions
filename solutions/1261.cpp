// 1261. Find Elements in a Contaminated Binary Tree
class FindElements {
    public:
        FindElements(TreeNode* root) {
            recover(root, 0);
        }
        
        bool find(int target) {
            return exists.contains(target);
        }
    private:
        unordered_set<int> exists;
        void recover(TreeNode* root, int x) {
            if (!root)
                return;
            root->val=x;
            exists.insert(x);
            recover(root->left, x*2+1);
            recover(root->right, x*2+2);
        }
    };