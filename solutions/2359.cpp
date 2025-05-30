// 2359. Find Closest Node to Given Two Nodes
class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int> visited(edges.size());
        queue<pair<int, int>> bfs;
        bfs.push({node1, 1}), bfs.push({node2, -1});
        while (!bfs.empty()) {
            int sz=bfs.size(), rt=INT_MAX;
            for (int i=0; i<sz; ++i) {
                auto [curr, src]=bfs.front();
                bfs.pop();

                if (visited[curr]*src<0)
                    rt=min(rt, curr);
                visited[curr]=src;
                
                if (edges[curr]!=-1 && visited[edges[curr]]!=src)
                    bfs.push({edges[curr], src});
            }
            if (rt!=INT_MAX)
                return rt;
        }
        return -1;
    }
};