// 995. Minimum Number of K Consecutive Bit Flips
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        vector<bool> parity(nums.size()+1);
        bool curr_parity=0;
        int num_flips=0;
        for (int i=0; i<nums.size(); ++i) {
            curr_parity^=parity[i];
            if (nums[i]==curr_parity) {
                num_flips++;
                curr_parity=!curr_parity;
                if (i+k-1>=nums.size())
                    return -1;
                parity[i+k]=!parity[i+k];
            }
        }
        return num_flips;
    }
};