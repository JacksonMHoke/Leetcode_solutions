# 1905. Count Sub Islands
class Solution:
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        dirs=[0,-1,0,1,0]
        n=len(grid1)
        m=len(grid1[0])
        def dfs(i, j):
            if grid2[i][j]!=1:
                return False
            rt=True
            if grid1[i][j]!=1:
                rt=False

            grid2[i][j]=2
            
            for k in range(4):
                x, y = i+dirs[k], j+dirs[k+1]
                if x>=0 and x<n and y>=0 and y<m and grid2[x][y]==1:
                    rt&=dfs(x, y)
            return rt
        rt=0
        for i in range(n):
            for j in range(m):
                rt+=int(dfs(i, j))
        return rt
            