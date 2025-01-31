// 827. Making A Large Island
class Solution {
public:
    int fill(vector<vector<int>>& grid, int i, int j, int val) {
        if (i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0 || grid[i][j]==val)
            return 0;
        grid[i][j]=val;
        return 1+fill(grid, i+1, j, val)+fill(grid, i-1, j, val)+fill(grid, i, j+1, val)+fill(grid, i, j-1, val);
    }

    int calc(vector<vector<int>>& grid, vector<int>& sizes, vector<int>& used, int i, int j, int dir) {
        int val=0, n=grid.size(), m=grid[0].size();
        if (i>=0 && i<n && j>=0 && j<m && !used[grid[i][j]]) {
            val=sizes[grid[i][j]];
            used[grid[i][j]]=1;
        }
        if (dir<3)
            val+=calc(grid, sizes, used, i+(dir==0)-(dir!=0), j+(dir==2)-(dir!=2), dir+1);
        if (i>=0 && i<n && j>=0 && j<m)
            used[grid[i][j]]=0;
        return val;
    }

    int largestIsland(vector<vector<int>>& grid) {
        vector<int> sizes(2);
        int currGroup=2, n=grid.size(), m=grid[0].size();
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                if (grid[i][j]==1)
                    sizes.push_back(fill(grid, i, j, currGroup++));
        int rt=1;
        vector<int> used(sizes.size()+1);
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                rt=max(rt, (grid[i][j]==0)+calc(grid, sizes, used, i, j+1, 0));
        return rt;
    }
};