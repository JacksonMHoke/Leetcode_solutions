// 834. Sum of Distances in Tree

class Solution {
public:
    int count_dfs(vector<vector<int>>& adj_list, vector<int>& count, vector<int>& rt, int i, int prev) {
        if (adj_list[i].empty())
            return 1;
        count[i]=1;
        for (auto child : adj_list[i]) {
            if (child==prev)
                continue;
            count[i]+=count_dfs(adj_list, count, rt, child, i);
            rt[i]+=rt[child];
        }
        rt[i]+=count[i]-1;
        return count[i];
    }

    void calculate_child_sums(vector<vector<int>>& adj_list, vector<int>& count, vector<int>& rt, int i, int prev) {
        int n=adj_list.size();
        for (auto child : adj_list[i]) {
            if (child==prev)
                continue;
            rt[child]=(rt[i]-count[child])+(n-count[child]);
            calculate_child_sums(adj_list, count, rt, child, i);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj_list(n);
        for (auto& edge : edges) {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }

        vector<int> rt(n);
        vector<int> count(n);
        count_dfs(adj_list, count, rt, 0, -1);
        calculate_child_sums(adj_list, count, rt, 0, -1);
        return rt;
    }
};