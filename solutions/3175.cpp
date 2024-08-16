// 3175. Find The First Player to win K Games in a Row
class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int maxI=0, wins=0, curr=0;
        for (int i=1; i<skills.size(); ++i) {
            if (skills[curr]>skills[i])
                wins++;
            else {
                wins=1;
                curr=i;
            }
            if (skills[maxI]<skills[i])
                maxI=i;
            if (wins==k)
                return curr;
        }
        return maxI;
    }
};