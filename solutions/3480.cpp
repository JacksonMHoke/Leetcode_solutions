//3480. Maximize Subarrays After Removing One Conflicting Pair
class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        for (auto& v : conflictingPairs)
            if (v[0]>v[1])
                swap(v[0], v[1]);
        conflictingPairs.push_back({0, n+1});
        sort(conflictingPairs.begin(), conflictingPairs.end(), [](const vector<int>& lhs, const vector<int>& rhs) { return lhs[1]<rhs[1] || lhs[1]==rhs[1] && lhs[0]>rhs[0]; });
        long long rt=0, largestSave=0, i=1, idx=0, left=0;
        while (i<=n) {
            long long currLeft=left, currSave=0;
            while (idx<conflictingPairs.size() && conflictingPairs[idx][1]==i) {
                if (conflictingPairs[idx][0]>=left) {
                    currLeft=left;
                    left=conflictingPairs[idx][0];
                } else if (currLeft<conflictingPairs[idx][0]) {
                    currLeft=conflictingPairs[idx][0];
                }
                idx++;
            }
            int tmpIdx=idx, right=i;
            while (tmpIdx<conflictingPairs.size() && currLeft<left) {
                currSave+=(left-currLeft)*(conflictingPairs[tmpIdx][1]-right);
                currLeft=max(currLeft, conflictingPairs[tmpIdx][0]+0ll);
                right=conflictingPairs[tmpIdx][1];
                tmpIdx++;
            }
            largestSave=max(largestSave, currSave);
            rt+=i-left;
            i++;
        }
        return rt+largestSave;
    }
};