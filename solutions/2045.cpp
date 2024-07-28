// 2045. Second Minimum Time to Reach Destination
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        queue<int> bfs;
        vector<vector<int>> adj_list(n+1);
        for (auto& edge : edges) {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }

        bfs.push(1);
        vector<int> dists(n+1);
        vector<bool> foundDistPlusOne(n+1);
        int minDist=-1, currTime=0, dist=0;
        bool last=false;
        while (!bfs.empty()) {
            queue<int> temp;
            while (!bfs.empty()) {
                int vertex=bfs.front();
                bfs.pop();

                if (vertex==n)
                    last=true;

                for (auto neighbor : adj_list[vertex]) {
                    if (!dists[neighbor]) {
                        dists[neighbor]=dist;
                        temp.push(neighbor);
                    }
                    if (dists[neighbor]==dist-1)
                        foundDistPlusOne[neighbor]=true;
                }
            }
            dist++;
            bfs=temp;
        }

        bfs=queue<int>();
        bfs.push(1);
        vector<bool> visited(n+1);
        last=false;
        while (!bfs.empty() && !last) {
            queue<int> temp;
            currTime+=((currTime/change)%2)*(change-currTime%change)+time;
            while (!bfs.empty()) {
                int vertex=bfs.front();
                bfs.pop();

                if (vertex==n)
                    last=true;

                for (auto neighbor : adj_list[vertex]) {
                    if (foundDistPlusOne[vertex])
                        foundDistPlusOne[neighbor]=true;
                    if (!visited[neighbor]) {
                        visited[neighbor]=true;
                        temp.push(neighbor);
                    }
                }
            }
            bfs=temp;
        }
        if (foundDistPlusOne[n])
                return currTime;
        currTime+=((currTime/change)%2)*(change-currTime%change)+time;
        return currTime;
    }
};