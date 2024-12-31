// 983. Minimum Cost For Tickets
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), INT_MAX);
        int prev=0;
        for (int i=0; i<days.size(); ++i) {
            dp[i]=min(dp[i], prev+costs[0]);

            auto it = upper_bound(days.begin()+i, days.end(), days[i]+6);
            int index = it-days.begin()-1;
            dp[index]=min(dp[index], prev+costs[1]);

            it = upper_bound(days.begin()+i, days.end(), days[i]+29);
            index = it-days.begin()-1;
            dp[index]=min(dp[index], prev+costs[2]);

            prev=dp[i];
        }
        return dp[days.size()-1];
    }
};