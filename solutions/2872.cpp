// 2872. Maximum Number of K-Divisible Components
class Solution {
public:
    int calculateSums(vector<vector<int>>& adjList, vector<int>& values, vector<int>& sums, int k, int curr, int prev) {
        int s=values[curr];
        for (auto neigh : adjList[curr]) {
            if (neigh==prev)
                continue;
            s=(s+calculateSums(adjList, values, sums, k, neigh, curr))%k;
        }
        sums[curr]=s;
        return s;
    }

    void traverse(vector<vector<int>>& adjList, vector<int>& sums, int& splits, int k, int curr, int prev) {
        if (sums[curr]%k==0)
            splits++;
        for (auto neigh : adjList[curr]) {
            if (neigh==prev)
                continue;
            traverse(adjList, sums, splits, k, neigh, curr);
        }
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adjList(n);
        vector<int> sums(n);
        for (auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        calculateSums(adjList, values, sums, k, 0, -1);
        int splits=0;
        traverse(adjList, sums, splits, k, 0, -1);
        return splits;
    }
};