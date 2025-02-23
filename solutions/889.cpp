// 889. Construct Binary Tree from Preorder and Postorder Traversal
class Solution {
    public:
        void recursion(TreeNode* root, vector<int>& preorder, vector<int>& postorder, stack<int>& s, int& i, int& j) {
            s.push(root->val);
            if (!s.empty() && s.top()==postorder[j]) {
                s.pop();
                j++;
                return;
            }
    
    
            root->left=new TreeNode(preorder[++i]);
            recursion(root->left, preorder, postorder, s, i, j);
            if (s.top()==postorder[j]) {
                s.pop();
                j++;
                return;
            }
    
            root->right=new TreeNode(preorder[++i]);
            recursion(root->right, preorder, postorder, s, i, j);
            if (s.top()==postorder[j]) {
                s.pop();
                j++;
                return;
            }
        }
    
        TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
            TreeNode* root=new TreeNode(preorder[0]);
            stack<int> s;
            int i=0, j=0;
            recursion(root, preorder, postorder, s, i, j);
            return root;
        }
    };