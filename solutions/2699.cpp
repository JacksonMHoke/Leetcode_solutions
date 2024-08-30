// 2699. Modify Graph Edge Weights

//idea is to run djikstras from end to source without using -1 edges to find shortest paths to all nodes connected to destination
//then we run djikstras from source using -1 edges as 1 and when we finally find a connection to a node connected to destination we
//change -1 edge to whatever it needs to be if possible to fulfill target
class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<vector<array<int, 3>>> adj_list(n);
        for (int i=0; i<edges.size(); ++i) {
            adj_list[edges[i][0]].push_back({edges[i][1], edges[i][2], i});
            adj_list[edges[i][1]].push_back({edges[i][0], edges[i][2], i});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2;
        pq2.push({0, destination});
        vector<int> dist2(n, INT_MAX);

        //djikstras from destination without -1 weights
        while (!pq2.empty()) {
            auto [d, curr] = pq2.top();
            pq2.pop();

            if (dist2[curr]<d)
                continue;

            for (auto [to, weight, i] : adj_list[curr]) {
                if (weight==-1)
                    continue;
                if (dist2[to]>d+weight) {
                    dist2[to]=d+weight;
                    pq2.push({d+weight, to});
                }
            }
        }

        //if path already lower than target without -1s its impossible
        if (dist2[source]<target)
            return {};
        //if path is exactly target we can ignore -1s and return edges
        if (dist2[source]==target) {
            for (int j=0; j<edges.size(); ++j) {
                if (edges[j][2]==-1)
                    edges[j][2]=(int)2e9;
            }
            return edges;
        }
        dist2[destination]=0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, source});
        vector<int> dist(n, INT_MAX);

        //djikstras with -1 weights counting as 1 until graph is connected
        while (!pq.empty()) {
            auto [d, curr] = pq.top();
            pq.pop();

            if (dist[curr]<d)
                continue;
            
            if (curr==destination)
                break;

            for (auto [to, weight, i] : adj_list[curr]) {
                if (weight==-1) {
                    //if there exists an edge weight for this -1 edge that fulfills target
                    if (target-dist2[to]-d>0) {
                        edges[i][2]=target-dist2[to]-d;
                        for (int j=0; j<edges.size(); ++j) {
                            if (edges[j][2]==-1)
                                edges[j][2]=(int)2e9;
                        }
                        return edges;
                    } else
                        edges[i][2]=1;
                }
                if (dist[to]>d+edges[i][2]) {
                    dist[to]=d+edges[i][2];
                    pq.push({d+edges[i][2], to});
                }
            }
        }
        return {};
    }
};