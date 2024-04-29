// 2997. Minimum Number of Operations to Make Array XOR Equal to K
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int x=0;
        for (auto num : nums)
            x^=num;
        return __builtin_popcount(x^k);
    }
};