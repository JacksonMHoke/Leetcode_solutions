// 330. Patching Array
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long interval=1;
        int patches=0;
        int i=0;
        while (interval<=n) {
            if (i<nums.size() && nums[i]<=interval) {
                interval+=nums[i++];
            } else {
                interval*=2;
                patches++;
            }
        }
        return patches;
    }
};