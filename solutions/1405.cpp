// 1405. Longest Happy String
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string rt;
        priority_queue<pair<int, char>> pq;
        if (a) pq.push({a, 'a'});
        if (b) pq.push({b, 'b'});
        if (c) pq.push({c, 'c'});
        while (pq.size()>1) {
            int ch1=pq.top().second;
            int amount1=pq.top().first;
            pq.pop();

            int ch2=pq.top().second;
            int amount2=pq.top().first;
            pq.pop();

            if (amount1>=2) {
                rt+=string(2, ch1);
                amount1-=2;
            } else {
                rt+=ch1;
                amount1--;
            }

            if (amount2>amount1 && amount2>=2) {
                rt+=string(2, ch2);
                amount2-=2;
            } else {
                rt+=ch2;
                amount2--;
            }

            if (amount1>0)
                pq.push({amount1, ch1});
            if (amount2>0)
                pq.push({amount2, ch2});
        }

        if (!pq.empty())
            rt+=string(min(2, pq.top().first), pq.top().second);

        return rt;
    }
};