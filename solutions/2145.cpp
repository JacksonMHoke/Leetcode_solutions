// 2145. Count the Hidden Sequences
class Solution {
    public:
        int numberOfArrays(vector<int>& differences, int lower, int upper) {
            long long lowest=0, highest=0, curr=0;
            for (int i=0; i<differences.size(); ++i) {
                curr+=differences[i];
                lowest=min(curr, lowest);
                highest=max(curr, highest);
            }
            return max((upper-lower)-(highest-lowest)+1, 0ll);
        }
    };