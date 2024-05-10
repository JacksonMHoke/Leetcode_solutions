// 506. Relative Ranks
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> rt(score.size());
        string medals[3]={"Gold Medal", "Silver Medal", "Bronze Medal"};
        vector<pair<int, int>> v;
        for (int i=0; i<score.size(); ++i)
            v.push_back({-score[i], i});
        sort(v.begin(), v.end());
        for (int i=0; i<v.size(); ++i) {
            if (i<3)
                rt[v[i].second]=medals[i];
            else
                rt[v[i].second]=to_string(i+1);
        }
        return rt;
    }
};