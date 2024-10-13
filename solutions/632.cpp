// 632. Smallest Range Covering Elements from K Lists
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> indexes(nums.size());
        set<pair<int, int>> coverage;
        for (int i=0; i<nums.size(); ++i)
            coverage.insert({nums[i][0], i});
        int smallest_range=INT_MAX;
        vector<int> best_range(2);
        while (!coverage.empty()) {
            int low=coverage.begin()->first;
            int high=coverage.rbegin()->first;
            int i=coverage.begin()->second;
            if (high-low<smallest_range) {
                best_range[0]=low;
                best_range[1]=high;
                smallest_range=high-low;
            }

            coverage.erase(coverage.begin());
            indexes[i]++;
            if (indexes[i]>=nums[i].size())
                break;
            coverage.insert({nums[i][indexes[i]], i});
        }
        return best_range;
    }
};