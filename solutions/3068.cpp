// 3068. Find the Maximum Sum of Node Values
class Solution {
public:
    pair<long long, long long> helper(vector<int>& nums, int k, vector<vector<int>>& adj_list, int i, int parent=-1) {
        if (adj_list[i].size()==1 && parent!=-1)
            return {nums[i]^k, nums[i]};
        long long s=0;
        vector<long long> diffs;
        for (int j=0; j<adj_list[i].size(); ++j) {
            if (adj_list[i][j]==parent)
                continue;
            auto p = helper(nums, k, adj_list, adj_list[i][j], i);
            diffs.push_back(p.first-p.second);
            s+=p.second;
        }
        sort(diffs.begin(), diffs.end());
        long long best_odd=INT_MIN, best_even=s, change=0;
        int children=diffs.size();
        for (int j=children-1; j>=0; --j) {
            change+=diffs[j];
            if ((children-j)%2==0)
                best_even=max(best_even, change+s);
            else
                best_odd=max(best_odd, change+s);
        }
        return {max((nums[i]^k)+best_even, nums[i]+best_odd), max(nums[i]+best_even, (nums[i]^k)+best_odd)};
    }

    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        vector<vector<int>> adj_list(nums.size(), vector<int>());
        for (int i=0; i<edges.size(); ++i) {
            adj_list[edges[i][0]].push_back(edges[i][1]);
            adj_list[edges[i][1]].push_back(edges[i][0]);
        }
        return helper(nums, k, adj_list, 0).second;
    }
};

/*
Was stupid and didn't find greedy solution. Here is 3 line python solution as well
class Solution:
    def maximumValueSum(self, nums: List[int], k: int, edges: List[List[int]]) -> int:
        best_sum = sum(max(n, k ^ n) for n in nums)
        cnt = sum((n ^ k) > n for n in nums)  
        return best_sum - (min(abs(n - (n ^ k)) for n in nums) if cnt % 2 else 0)
*/