// 2200. Find All K-Distant Indices in an Array
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> rt;
        int n=nums.size(), counter=0, l=0, r=0;
        for (int i=0; i<n; ++i) {
            while (r<n && r<=i+k)
                counter+=nums[r++]==key;
            while (l<i-k)
                counter-=nums[l++]==key;
            if (counter)
                rt.push_back(i);
        }
        return rt;
    }
};