// 3160. Find the Number of Distinct Colors Among the Balls
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> colorFreqs;
        unordered_map<int, int> color;
        vector<int> rt;
        int numColors=0;
        for (int i=0; i<queries.size(); ++i) {
            if (color.contains(queries[i][0])) {
                numColors-=colorFreqs[color[queries[i][0]]]==1;
                colorFreqs[color[queries[i][0]]]--;
            }
            color[queries[i][0]]=queries[i][1];
            numColors+=colorFreqs[queries[i][1]]==0;
            colorFreqs[queries[i][1]]++;
            rt.push_back(numColors);
        }
        return rt;
    }
};