// 2127. Maximum Employees to Be Invited to a Meeting
class Solution {
public:
    array<int, 3> dfs(vector<int>& favorite, vector<int>& depths, vector<array<int, 3>>& memo, int depth, int i) {
        if (memo[i][0]==2 && memo[i][2]==favorite[i] && favorite[favorite[i]]==i)
            return {2, 2, i};
        if (memo[i][0]!=-1)
            return memo[i];
        if (depths[i]!=-1)
            return {depth-depths[i], 0, i};
        depths[i]=depth;
        array<int, 3> rt=dfs(favorite, depths, memo, depth+1, favorite[i]);
        rt[1]++;
        memo[i]=rt;
        depths[i]=-1;
        return rt;
    }

    int maximumInvitations(vector<int>& favorite) {
        int n=favorite.size(), largest_cycle=0, sum_independent=0;
        vector<int> depths(n, -1);
        vector<array<int, 3>> memo(n, {-1,-1,-1});
        unordered_map<int, int> largest_path;
        for (int i=0; i<n; ++i) {
            auto [cycle_size, depth, ending_node]=dfs(favorite, depths, memo, 0, i);
            largest_cycle=max(largest_cycle, cycle_size);
            if (cycle_size==2)
                largest_path[ending_node]=max(largest_path[ending_node], depth);
        }
        
        for (auto& p : largest_path) {
            if (largest_path.contains(favorite[p.first]))
                sum_independent--;
            sum_independent+=p.second;
        }
        return max(sum_independent, largest_cycle);
    }
};