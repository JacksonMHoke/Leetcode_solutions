// 846. Hand of Straights
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        if (hand.size()%k)
            return false;
        
        unordered_map<int, int> freqs;
        for (auto num : hand)
            freqs[num]++;
        vector<pair<int, int>> sorted(freqs.begin(), freqs.end());
        sort(sorted.begin(), sorted.end());

        for (int i=0; i<sorted.size(); ++i) {
            int freq=sorted[i].second;
            int num=sorted[i].first;
            if (freq) {
                if (i+k>sorted.size())
                    return false;
                for (int j=0; j<k; ++j) {
                    if (sorted[i+j].second<freq || sorted[i+j].first-j!=num)
                        return false;
                    sorted[i+j].second-=freq;
                }
            }
        }

        return true;
    }
};