// 310. Minimum Height Trees
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n==1)
            return vector<int>{0};
        vector<unordered_set<int>> neighbors(n);
        for (auto& edge : edges) {
            neighbors[edge[0]].insert(edge[1]);
            neighbors[edge[1]].insert(edge[0]);
        }

        vector<int> leaves;

        for (int i=0; i<n; ++i) {
            if (neighbors[i].size()==1) {
                leaves.push_back(i);
            }
        }

        while (!leaves.empty()) {
            vector<int> newLeaves;
            for (int i=0; i<leaves.size(); ++i) {
                for (auto& neighbor : neighbors[leaves[i]]) {
                    neighbors[neighbor].erase(leaves[i]);
                    if (neighbors[neighbor].size()==1)
                        newLeaves.push_back(neighbor);
                }
            }
            if (newLeaves.empty())
                return leaves;
            leaves=newLeaves;
        }
        return leaves;
    }
};