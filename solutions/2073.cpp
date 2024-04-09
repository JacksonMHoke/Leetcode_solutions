// 2073. Time Needed to Buy Tickets
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int rt=0;
        for (int i=0; i<=k; ++i)
            rt+=min(tickets[i], tickets[k]);
        for (int i=k+1; i<tickets.size(); ++i)
            rt+=min(tickets[i], tickets[k]-1);
        return rt;
    }
};