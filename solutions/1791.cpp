// 1791. Find Center of Star Graph
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        long long s=0, n=edges.size()+1;
        for (auto& edge : edges)
           s+=edge[0]+edge[1];
        return (s-n*(n+1)/2)/(n-2);
    }
};