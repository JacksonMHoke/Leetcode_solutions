// 1857. Largest Color Value in a Directed Graph
class Solution {
    public:
        int largestPathValue(string colors, vector<vector<int>>& edges) {
            int n=colors.length(), rt=0, visited=0;
            vector<vector<int>> adjList(n), maxColors(n, vector<int>(26));
            vector<int> inDeg(n); 
            for (auto& edge : edges) {
                adjList[edge[0]].push_back(edge[1]);
                inDeg[edge[1]]++;
            }
    
            queue<int> zeroDegs;
            for (int i=0; i<n; ++i) {
                if (inDeg[i]==0)
                    zeroDegs.push(i);
            }
    
            while (!zeroDegs.empty()) {
                int curr=zeroDegs.front();
                visited++;
                zeroDegs.pop();
    
                maxColors[curr][colors[curr]-'a']++;
                if (adjList[curr].empty())
                    rt=max(rt, *max_element(maxColors[curr].begin(), maxColors[curr].end()));
                
                for (auto nei : adjList[curr]) {
                    inDeg[nei]--;
                    if (inDeg[nei]==0)
                        zeroDegs.push(nei);
                    for (int i=0; i<26; ++i)
                        maxColors[nei][i]=max(maxColors[nei][i], maxColors[curr][i]);
                }
            }
            
            return (visited==n)? rt: -1;
        }
    };