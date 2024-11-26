// 2924. Find Champion II
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> in_edges(n);
        for (int i=0; i<edges.size(); ++i)
            in_edges[edges[i][1]]++;
        int champion=-1;
        for (int i=0; i<n; ++i) {
            if (in_edges[i]==0) {
                if (champion!=-1)
                    return -1;
                champion=i;
            }
        }
        return champion;
    }
};