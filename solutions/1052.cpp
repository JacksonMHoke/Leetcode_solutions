// 1052. Grumpy Bookstore Owner
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int window=0, ans=0, tot=0;
        for (int i=0; i<customers.size(); ++i) {
            if (grumpy[i])
                window+=customers[i];
            else
                tot+=customers[i];
            if (i-minutes>=0 && grumpy[i-minutes])
                window-=customers[i-minutes];
            ans=max(window, ans);
        }
        return ans+tot;
    }
};