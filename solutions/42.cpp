// 42. Trapping Rain Water
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n==0) return 0;
        
        vector<int> l(n, 0);
        vector<int> r(n, 0);
        
        //filling up arrays that keep track of max
        //element from left and right
        l[0]=height[0];
        r[n-1]=height[n-1];
        for (int i=1; i<n; ++i) {
            l[i]=max(l[i-1], height[i]);
            r[n-i-1]=max(r[n-i], height[n-i-1]);
        }
        
        //calculating amount of rainwater using
        //l and r arrays
        int rt=0;
        for (int i=0; i<n; ++i) {
            rt+=min(l[i],r[i])-height[i];
        }
        return rt;
    }
};