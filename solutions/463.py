# 463. Island Perimeter
class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        return sum([sum([(j==0 or grid[i][j-1]==0)+(j==len(r)-1 or grid[i][j+1]==0)+(i==0 or grid[i-1][j]==0)+(i==len(grid)-1 or grid[i+1][j]==0) for j, val in enumerate(r) if val==1]) for i, r in enumerate(grid)])