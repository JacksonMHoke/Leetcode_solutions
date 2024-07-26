// 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> adj_list(n);
        for (auto& edge : edges) {
            adj_list[edge[0]].push_back({edge[1], edge[2]});
            adj_list[edge[1]].push_back({edge[0], edge[2]});
        }
        int rt=0;
        int min_neighbors=INT_MAX;
        for (int i=0; i<n; ++i) {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> next_shortest;
            vector<int> shortest_found(n, INT_MAX);
            vector<bool> is_valid_neighbor(n);
            next_shortest.push({0, i});
            int valid_neighbors=0;
            while (!next_shortest.empty()) {
                int dist=next_shortest.top().first;
                int city=next_shortest.top().second;
                next_shortest.pop();

                if (is_valid_neighbor[city])
                    continue;

                is_valid_neighbor[city]=true;
                valid_neighbors++;

                for (auto& neighbor : adj_list[city]) {
                    int new_dist=neighbor.second+dist;
                    if (new_dist<shortest_found[neighbor.first] && new_dist<=distanceThreshold) {
                        shortest_found[neighbor.first]=new_dist;
                        next_shortest.push({new_dist, neighbor.first});
                    }
                }
            }

            if (valid_neighbors<=min_neighbors) {
                min_neighbors=valid_neighbors;
                rt=i;
            }
        }
        return rt;
    }
};