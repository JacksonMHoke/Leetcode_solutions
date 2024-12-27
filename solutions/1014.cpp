// 1014. Best Sightseeing Pair
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int currL=0, i=0, best=0;
        for (int i=0; i<values.size(); ++i) {
            best=max(best, currL+values[i]);
            currL=max(currL, values[i]);
            currL--;
        }
        return best;
    }
};