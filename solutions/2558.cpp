// 2558. Take Gifts From the Richest Pile
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(), gifts.end());
        for (int i=0; i<k; ++i) {
            pq.push(sqrt(pq.top()));
            pq.pop();
        }
        long long rt=0;
        while (!pq.empty()) {
            rt+=pq.top();
            pq.pop();
        }
        return rt;
    }
};