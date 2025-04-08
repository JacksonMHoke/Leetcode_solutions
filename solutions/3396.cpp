// 3396. Minimum Number of Operations to Make Elements in Array Distinct
class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            vector<int> freqs(101);
            for (int i=nums.size()-1; i>=0; --i) {
                freqs[nums[i]]++;
                if (freqs[nums[i]]>1)
                    return i/3+1;
            }
            return 0;
        }
    };