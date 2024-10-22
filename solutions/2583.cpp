// 2583. Kth Largest Sum in a Binary Tree
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> min_heap;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            queue<TreeNode*> next;
            long long sum=0;
            while (!q.empty()) {
                TreeNode* curr=q.front();
                q.pop();
                sum+=curr->val;

                if (curr->left)
                    next.push(curr->left);
                if (curr->right)
                    next.push(curr->right);
            }
            swap(q, next);
            min_heap.push(sum);
            while (min_heap.size()>k)
                min_heap.pop();
        }
        return min_heap.size()>=k ? min_heap.top() : -1;
    }
};