// 2381. Shifting Letters II
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> cumulativeShifts(s.length());
        for (int i=0; i<shifts.size(); ++i) {
            if (shifts[i][2]==1) {
                cumulativeShifts[shifts[i][0]]++;
                if (shifts[i][1]+1<s.length())
                    cumulativeShifts[shifts[i][1]+1]--;
            } else {
                cumulativeShifts[shifts[i][0]]--;
                if (shifts[i][1]+1<s.length())
                    cumulativeShifts[shifts[i][1]+1]++;
            }
        }
        int curr=0;
        for (int i=0; i<s.length(); ++i) {
            curr+=cumulativeShifts[i];
            s[i]=(s[i]-'a'+curr)%26+'a';
            if (s[i]<'a')
                s[i]+=26;
        }
        return s;
    }
};