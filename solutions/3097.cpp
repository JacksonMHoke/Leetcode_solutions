// 3097. Shortest Subarray With OR at Least K II
class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        if (k==0)
            return 1;
        vector<int> frq(32);
        int curr=0, j=0, rt=INT_MAX;
        for (int i=0; i<nums.size(); ++i) {
            curr|=nums[i];
            int temp=nums[i];
            for (int b=0; temp>0; ++b, temp>>=1)
                frq[b]+=temp&1;
            while (curr>=k) {
                temp=nums[j];
                for (int b=0; temp>0; ++b, temp>>=1) {
                    frq[b]-=temp&1;
                    if (frq[b]==0 && temp&1)
                        curr-=(1<<b);
                }
                ++j;
            }
            if (j>i)
                return 1;
            if (j>0 && curr|nums[j-1]>k)
                rt=min(rt, i-j+2);
        }
        return rt!=INT_MAX ? rt : -1;
    }
};