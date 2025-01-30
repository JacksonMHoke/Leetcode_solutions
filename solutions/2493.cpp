// 2493. Divide Nodes Into the Maximum Number of Groups
class Solution {
public:
    int farthestNode(vector<vector<int>>& adj_list, vector<int>& visited, int i) {
        queue<pair<int, int>> bfs;
        bfs.push({i, 1});
        int furthest=1;
        while (!bfs.empty()) {
            auto [curr, d]=bfs.front();
            bfs.pop();

            visited[i]=1;
            furthest=d;

            for (int nei : adj_list[curr]) {
                if (visited[nei]==0) {
                    bfs.push({nei, d+1});
                    visited[nei]=1;
                }
            }
        }
        return furthest;
    }

    bool isBipartite(vector<vector<int>>& adj_list, vector<int>& group, vector<int>& connected, int i) {
        queue<int> bfs;
        bfs.push(i);
        while (!bfs.empty()) {
            int curr=bfs.front();
            bfs.pop();

            connected.push_back(curr);

            for (int nei : adj_list[curr]) {
                if (group[curr]==group[nei])
                    return false;
                if (group[nei]==-1) {
                    group[nei]=!group[curr];
                    bfs.push(nei);
                }
            }
        }
        return true;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<int> group(n+1, -1);
        vector<vector<int>> adj_list(n+1);
        for (auto& edge : edges) {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }

        int rt=0;
        for (int i=1; i<=n; ++i) {
            if (group[i]==-1) {
                group[i]=0;
                vector<int> connected;
                bool isBip=isBipartite(adj_list, group, connected, i);
                if (!isBip)
                    return -1;
                int furthest=0;
                for (int j=0; j<connected.size(); ++j) {
                    vector<int> visited(n+1);
                    furthest=max(furthest, farthestNode(adj_list, visited, connected[j]));
                }
                rt+=furthest;
            }
        }
        return rt;
    }
};