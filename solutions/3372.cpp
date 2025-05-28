// 3372. Maximize the Number of Target Nodes After Connecting Trees I
class Solution {
public:
    int numTargets(vector<vector<int>>& adjList, int src, int k) {
        queue<int> bfs;
        vector<int> visited(adjList.size());
        bfs.push(src);
        visited[src]=1;
        int rt=0;

        while (!bfs.empty() && k>=0) {
            int sz=bfs.size();
            for (; sz>0; --sz) {
                int curr=bfs.front();
                bfs.pop();
                rt++;

                for (auto nei : adjList[curr]) {
                    if (visited[nei])
                        continue;
                    bfs.push(nei);
                    visited[nei]=1;
                }
            }
            k--;
        }
        return rt;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n=edges1.size()+1, m=edges2.size()+1, mx=0;
        vector<vector<int>> adjList1(n), adjList2(m);
        vector<int> rt(n);

        for (auto& edge : edges1) {
            adjList1[edge[0]].push_back(edge[1]);
            adjList1[edge[1]].push_back(edge[0]);
        }

        for (auto& edge : edges2) {
            adjList2[edge[0]].push_back(edge[1]);
            adjList2[edge[1]].push_back(edge[0]);
        }

        for (int i=0; i<m; ++i)
            mx=max(mx, numTargets(adjList2, i, k-1));
        
        for (int i=0; i<n; ++i)
            rt[i]=mx+numTargets(adjList1, i, k);
        
        return rt;
    }
};