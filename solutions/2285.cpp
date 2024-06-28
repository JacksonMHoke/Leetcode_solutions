// 2285. Maximum Total Importance of Roads
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> degrees(n);
        for (auto& road : roads) {
            degrees[road[0]]++;
            degrees[road[1]]++;
        }
        sort(degrees.begin(), degrees.end());
        long long rt=0;
        for (int i=0; i<n; ++i) {
            rt+=degrees[i]*(i+1);
        }
        return rt;
    }
};