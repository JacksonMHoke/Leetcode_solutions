// 2799. Count Complete Subarrays in an Array
class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            vector<int> freq(2001, -1);
            int j=0, distinct=0, complete=0;
            for (int i=0; i<nums.size(); ++i) {
                if (freq[nums[i]]==-1) {
                    distinct++;
                    freq[nums[i]]++;
                }
            }
            for (int i=0; i<nums.size(); ++i) {
                while (distinct>0 && j<nums.size()) {
                    distinct-=(++freq[nums[j]]==1);
                    j++;
                }
                if (distinct>0)
                    break;
                complete+=nums.size()-j+1;
                distinct+=(--freq[nums[i]]==0);
            }
            return complete;
        }
    };