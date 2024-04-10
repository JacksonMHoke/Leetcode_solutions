// 950. Reveal Cards In Increasing Order
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size(), i=0;
        vector<int> rt(n);
        sort(deck.begin(), deck.end());
        queue<int> q;
        for (int i=0; i<deck.size(); ++i)
            q.push(i);
        while (q.size()>=2) {
            rt[q.front()]=deck[i++];
            q.pop();
            q.push(q.front());
            q.pop();
        }
        if (!q.empty())
            rt[q.front()]=deck[i++];
        return rt;
    }
};