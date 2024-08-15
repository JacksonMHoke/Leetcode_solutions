// 860. Lemonade Change
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives=0, tens=0;
        bool flag=false;
        for (int i=0; i<bills.size(); ++i) {
            if (bills[i]==5)
                fives++;
            else if (bills[i]==10) {
                flag|=(fives==0);
                fives--;
                tens++;
            } else {
                flag|=(fives<=2 && tens<=0) || (tens>=1 && fives<=0);
                if (tens) {
                    tens--;
                    fives--;
                } else
                    fives-=3;
            }
            if (flag)
                break;
        }
        return !flag;
    }
};