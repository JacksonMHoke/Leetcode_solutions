// 40. Combination Sum II
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> rt;
        vector<int> prev;
        sort(candidates.begin(), candidates.end());
        backtrack(rt, candidates, prev, target, 0);
        return rt;
    }
    
    void backtrack(vector<vector<int>>& rt, vector<int>& nums, vector<int>& prev, int remainder, int start) {
        if (remainder<0) { return; }
        else if (remainder==0) {
            rt.push_back(prev);
        }
        else {
            for (int i=start; i<nums.size(); ++i) {
                if (i!=start && i!=0 && nums[i]==nums[i-1]) { continue; }
                if (remainder-nums[i]<0) { return; }
                prev.push_back(nums[i]);
                backtrack(rt, nums, prev, remainder-nums[i], i+1);
                prev.pop_back();
            }
        }
    }
};