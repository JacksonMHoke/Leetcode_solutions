class Solution {
// 2976. Minimum Cost to Convert String I
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> path(26, vector<long long>(26, -1));
        for (int i=0; i<original.size(); ++i)
            if (cost[i]<path[original[i]-'a'][changed[i]-'a'] || path[original[i]-'a'][changed[i]-'a']==-1)
                path[original[i]-'a'][changed[i]-'a']=cost[i];

        for (int k=0; k<26; ++k) {
            for (int i=0; i<26; ++i) {
                for (int j=0; j<26; ++j) {
                    if (path[i][k]!=-1 && path[k][j]!=-1 && (path[i][j]==-1 || path[i][j]>path[i][k]+path[k][j])) {
                        path[i][j]=path[i][k]+path[k][j];
                    }
                }
            }
        }

        long long rt=0;
        for (int i=0; i<source.length(); ++i) {
            if (source[i]-'a'!=target[i]-'a') {
                rt+=path[source[i]-'a'][target[i]-'a'];
                if (path[source[i]-'a'][target[i]-'a']==-1)
                    return -1;
            }
        }
        return rt;
    }
};