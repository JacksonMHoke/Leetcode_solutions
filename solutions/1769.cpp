// 1769. Minimum Number of Operations to Move All Balls to Each Box
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int numMoves=0, numLeft=0, numRight=0;
        for (int i=0; i<boxes.length(); ++i) {
            numMoves+=numLeft;
            if (boxes[i]=='1')
                numLeft++;
        }

        vector<int> rt(boxes.size());
        for (int i=boxes.length()-1; i>=0; --i) {
            rt[i]=numMoves;
            if (boxes[i]=='1') {
                numLeft--;
                numRight++;
            }
            numMoves+=numRight-numLeft;
        }
        return rt;
    }
};