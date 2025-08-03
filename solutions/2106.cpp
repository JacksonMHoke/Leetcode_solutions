// 2106. Maximum Fruits Harvested After at Most K Steps
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int left=0, best=0, startIdx=lower_bound(fruits.begin(), fruits.end(), startPos, [] (const vector<int>& lhs, const int& rhs) { return lhs[0]<rhs; })-fruits.begin();
        int leftSum=accumulate(fruits.begin(), fruits.begin()+startIdx, 0, [&] (const int& total, const vector<int>& toAdd) { return total+toAdd[1]; }), curr=0;
        for (int i=startIdx; i<fruits.size() && fruits[i][0]-startPos<=k; ++i) {
            while (fruits[left][0]<startPos && (fruits[i][0]-startPos)*2+(startPos-fruits[left][0])>k) {
                leftSum-=fruits[left][1];
                left++;
            }
            curr+=fruits[i][1];
            best=max(best, curr+max(0, leftSum));
        }

        startIdx=upper_bound(fruits.begin(), fruits.end(), startPos, [] (const int& lhs, const vector<int>& rhs) { return lhs<rhs[0]; })-fruits.begin()-1;
        curr=0;
        int right=fruits.size()-1, rightSum=accumulate(fruits.begin()+startIdx+1, fruits.end(), 0, [&] (const int& total, const vector<int>& toAdd) { return total+toAdd[1]; });
        for (int i=startIdx; i>=0 && startPos-fruits[i][0]<=k; --i) {
            while (fruits[right][0]>startPos && (startPos-fruits[i][0])*2+(fruits[right][0]-startPos)>k) {
                rightSum-=fruits[right][1];
                right--;
            }
            curr+=fruits[i][1];
            best=max(best, curr+max(rightSum, 0));
        }
        return best;
    }
};