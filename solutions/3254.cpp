// 3254. Find the Power of K-Size Subarrays I
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> rt;
        int consec=0;
        for (int i=0; i<nums.size(); ++i) {
            consec=(i==0 || nums[i]==nums[i-1]+1) ? consec+1 : 1;
            if (i>=k-1)
                rt.push_back((consec>=k) ? nums[i] : -1);
        }
        return rt;
    }
};