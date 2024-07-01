// 1550. Three Consecutive Odds
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int consec_odds=0;
        for (int i=0; i<arr.size() && consec_odds<3; ++i) {
            if (arr[i]%2) consec_odds++;
            else consec_odds=0;
        }
        return consec_odds>=3;
    }
};