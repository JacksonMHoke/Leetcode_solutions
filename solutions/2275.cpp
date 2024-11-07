// 2275. Largest Combination With Bitwise AND Greater Than Zero
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> bits(32);
        for (int i=0; i<candidates.size(); ++i)
            for (int j=0; j<32 && candidates[i]>0; ++j, candidates[i]>>=1)
                bits[j]+=candidates[i]&1;
        return *max_element(bits.begin(), bits.end());
    }
};