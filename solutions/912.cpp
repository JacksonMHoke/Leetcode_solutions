// 912. Sort an Array
class Solution {
public:
    vector<int>& mergeSort(vector<int>& nums, int start, int end) {
        if (start==end)
            return {nums[start]};
        
        int mid=(start+end)/2;
        vector<int> left=mergeSort(nums, start, mid);
        vector<int> right=mergeSort(nums, mid+1, end);

        vector<int> rt;
        int i=0, j=0;
        while (i<left.size() && j<right.size()) {
            if (left[i]<right[j])
                rt.push_back(left[i++]);
            else
                rt.push_back(right[j++]);
        }

        while (i<left.size())
            rt.push_back(left[i++]);
        while (j<right.size())
            rt.push_back(right[j++]);
        return rt;
    }

    vector<int> sortArray(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};