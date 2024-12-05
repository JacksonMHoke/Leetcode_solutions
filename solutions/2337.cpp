// 2337. Move Pieces to Obtain a String
class Solution {
public:
    bool canChange(string start, string target) {
        int leftNeeded=0, rightSurplus=0;
        for (int i=0; i<start.length(); ++i) {
            if (start[i]=='R' && leftNeeded>0 || start[i]=='L' && rightSurplus>0 || leftNeeded<0 || rightSurplus<0 || target[i]=='L' && rightSurplus>0 || target[i]=='R' && leftNeeded>0)
                return false;
            leftNeeded+=(target[i]=='L')-(start[i]=='L');
            rightSurplus+=(start[i]=='R')-(target[i]=='R');
        }
        return leftNeeded==0 && rightSurplus==0;
    }
};