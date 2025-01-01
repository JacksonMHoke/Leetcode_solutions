// 1422. Maximum Score After Splitting a String
class Solution {
public:
    int maxScore(string s) {
        int score = 0;
        int numOnes = 0;
        int maxScore = -1;
        for (int i=0; i<s.length()-1; ++i) {
            if (s[i]=='0') {
                score++;
            } else {
                score--;
                numOnes++;
            }
            maxScore = max(maxScore, score);
        }
        if (s.back()=='1')
            numOnes++;
        return numOnes+maxScore;
    }
};