// 719. Find K-th Smallest Pair Distance
class Solution {
public:
    int pairsLT(vector<int>& nums, int guess) {
        int start=0, end=0, n=nums.size(), lt=0;
        while (end<n) {
            while (start<=end && nums[end]- nums[start]>guess)
                start++;
            lt+=end-start;
            end++;            
        }
        return lt;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int start=0, end=1e6;
        while (start<end) {
            int m=(start+end)/2;
            if (pairsLT(nums, m)<k) {
                start=m+1;
            } else {
                end=m;
            }
        }
        return start;
    }
};