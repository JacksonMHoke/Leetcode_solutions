// 1248. Count Number of Nice Subarrays
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_odds;
        prefix_odds[0]++;
        int odds=0, nice=0;
        for (int i=0; i<nums.size(); ++i) {
            odds+=nums[i]%2;
            prefix_odds[odds]++;
            nice+=prefix_odds[odds-k];
        }
        return nice;
    }
};