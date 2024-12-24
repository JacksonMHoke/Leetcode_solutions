// 3203. Find Minimum Diameter After Merging Two Trees
class Solution {
public:
    pair<int, int> furthestNode(vector<vector<int>>& graph, int curr, int prev) {
        int mx=-1, farNode=curr;
        for (auto& neigh : graph[curr]) {
            if (neigh==prev)
                continue;
            auto [dist, node]=furthestNode(graph, neigh, curr);
            if (dist>mx) {
                farNode=node;
                mx=dist;
            }
        }
        return {1+mx, farNode};
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<vector<int>> graph1(edges1.size()+1);
        vector<vector<int>> graph2(edges2.size()+1);
        for (int i=0; i<edges1.size(); ++i) {
            graph1[edges1[i][0]].push_back(edges1[i][1]);
            graph1[edges1[i][1]].push_back(edges1[i][0]);
        }
        for (int i=0; i<edges2.size(); ++i) {
            graph2[edges2[i][0]].push_back(edges2[i][1]);
            graph2[edges2[i][1]].push_back(edges2[i][0]);
        }
        int graph1Dia=furthestNode(graph1, furthestNode(graph1, 0, -1).second, -1).first;
        int graph2Dia=furthestNode(graph2, furthestNode(graph2, 0, -1).second, -1).first;
        return max({(graph1Dia+1)/2+(graph2Dia+1)/2+1, graph1Dia, graph2Dia});
    }
};