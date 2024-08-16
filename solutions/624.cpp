// 624. Maximum Distance in Arrays
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mn1=INT_MAX, mx1=INT_MIN, mn2=INT_MAX, mx2=INT_MIN;
        int mnIdx=-1;
        for (int i=0; i<arrays.size(); ++i) {
            if (arrays[i][0]<=mn1) {
                mnIdx=i;
                mn2=mn1;
                mn1=arrays[i][0];
            } else if (arrays[i][0]<mn2)
                mn2=arrays[i][0];
            
            if (arrays[i].back()>=mx1) {
                mx2=mx1;
                mx1=arrays[i].back();
            } else if (arrays[i].back()>mx2)
                mx2=arrays[i].back();
        }
        return (arrays[mnIdx].back()==mx1) ? max(mx2-mn1, mx1-mn2) : mx1-mn1;
    }
};