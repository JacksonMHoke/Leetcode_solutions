// 684. Redundant Connection
class Solution {
public:
    vector<int> unions;
    int find(int i) {
        if (unions[i]==i)
            return i;
        unions[i]=find(unions[i]);
        return unions[i];
    }
    bool union_tree(int i, int j) {
        if (find(i)==find(j))
            return false;
        unions[find(i)]=find(j);
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        unions=vector<int>(n+1);
        for (int i=1; i<=n; ++i)
            unions[i]=i;
        for (int i=0; i<n; ++i) {
            if (!union_tree(edges[i][0], edges[i][1])) {
                return edges[i];
            }
        }
        return {-1, -1};
    }
};