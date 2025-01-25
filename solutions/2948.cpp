// 2948. Make Lexicographically Smallest Array by Swapping Elements
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int i=0, n=nums.size();
        vector<int> indexes(n), rt(n);
        iota(indexes.begin(), indexes.end(), 0);
        sort(indexes.begin(), indexes.end(), [&](int lhs, int rhs) { return nums[lhs]<nums[rhs]; });
        sort(nums.begin(), nums.end());
        while (i<n) {
            int j=i+1;
            while (j<n && nums[j]-nums[j-1]<=limit)
                j++;
            sort(indexes.begin()+i, indexes.begin()+j);
            while (i<j) {
                rt[indexes[i]]=nums[i];
                i++;
            }
        }
        return rt;
    }
};