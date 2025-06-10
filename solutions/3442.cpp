// 3442. Maximum Difference Between Even and Odd Frequency I
class Solution {
public:
    int maxDifference(string s) {
        vector<int> freqs(26);
        for (auto c : s)
            freqs[c-'a']++;
        int biggestOdd=0, smallestEven=INT_MAX;
        for (int i=0; i<26; ++i) {
            if (freqs[i]==0)
                continue;
            if (freqs[i]%2)
                biggestOdd=max(biggestOdd, freqs[i]);
            else
                smallestEven=min(smallestEven, freqs[i]);
        }
        return biggestOdd-smallestEven;
    }
};