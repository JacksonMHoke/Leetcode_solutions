// 3243. Shortest Distance After Road Addition Queries I
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> answers;
        vector<vector<int>> adj_list(n);
        for (int i=0; i<n-1; ++i)
            adj_list[i].push_back(i+1);
        
        for (int i=0; i<queries.size(); ++i) {
            int from=queries[i][0], to=queries[i][1];
            adj_list[from].push_back(to);

            vector<bool> visited(n);
            queue<pair<int, int>> bfs;
            bfs.push({0, 0});
            while (!bfs.empty()) {
                auto [node, dist]=bfs.front();
                bfs.pop();

                if (node==n-1) {
                    answers.push_back(dist);
                    break;
                }

                for (auto neighbor : adj_list[node]) {
                    if (visited[neighbor])
                        continue;
                    visited[neighbor]=true;
                    bfs.push({neighbor, dist+1});
                }
            }
        }

        return answers;
    }
};