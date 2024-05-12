class Solution:
    def largestLocal(self, grid: List[List[int]]) -> List[List[int]]:
        return [[max([max(row[j-1:j+2]) for row in grid[i-1:i+2]]) for j in range(1, len(grid)-1)] for i in range(1, len(grid)-1)]
