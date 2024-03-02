// 977. Squares of a Sorted Array
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> neg_arr;
        vector<int> pos_arr;
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i]<0) {
                neg_arr.push_back(nums[i]*nums[i]);
            } else {
                pos_arr.push_back(nums[i]*nums[i]);
            }
        }

        vector<int> rt;
        int i=0, j=neg_arr.size()-1;
        while (j>=0 && i<pos_arr.size()) {
            if (pos_arr[i]<=neg_arr[j])
                rt.push_back(pos_arr[i++]);
            else
                rt.push_back(neg_arr[j--]);
        }

        while (j>=0)
            rt.push_back(neg_arr[j--]);
        while (i<pos_arr.size())
            rt.push_back(pos_arr[i++]);
        
        return rt;
    }
};