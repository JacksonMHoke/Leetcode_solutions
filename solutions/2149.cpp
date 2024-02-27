//Rearrange Array Elements by Sign

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pos=0, neg=1;
        vector<int> rt(nums.size());
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i]<0) {
                rt[neg]=nums[i];
                neg+=2;
            } else {
                rt[pos]=nums[i];
                pos+=2;
            }
        }
        return rt;
    }
};