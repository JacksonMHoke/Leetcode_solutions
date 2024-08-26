// 590. N-ary Tree Postorder Traversal
class Solution {
public:
    vector<int> postorder(Node* root) {
        if (!root)
            return {};

        stack<pair<Node*, int>> s;
        vector<int> rt;
        s.push({root, 0});

        while (!s.empty()) {
            Node* curr=s.top().first;
            int numVisits=s.top().second;

            s.top().second++;

            if (numVisits==curr->children.size()) {
                s.pop();
                rt.push_back(curr->val);
                continue;
            }
            
            s.push({curr->children[numVisits], 0});
        }
        return rt;
    }
};