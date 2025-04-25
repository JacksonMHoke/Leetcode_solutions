// 2845. Count of Interesting Subarrays
class Solution {
    public:
        long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
            long long rt=0;
            unordered_map<int, int> freqs;
            freqs[0]=1;
            int curr=0;
            for (int i=0; i<nums.size(); ++i) {
                curr=(curr+(nums[i]%modulo==k))%modulo;
                rt+=freqs[(curr+modulo-k)%modulo];
                freqs[curr]++;
            }
            return rt;
        }
    };