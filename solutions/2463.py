# 2463. Minimum Total Distance Traveled
class Solution:
    def minimumTotalDistance(self, robot: List[int], factory: List[List[int]]) -> int:
        robot=sorted(robot)
        factory=sorted(factory)
        @lru_cache(None)
        def dfs(i, j, k):
            if i==len(robot):
                return 0
            if j==len(factory):
                return float('inf')
            
            return min(dfs(i, j+1, 0), dfs(i+1, j, k+1)+abs(robot[i]-factory[j][0]) if k<factory[j][1] else float('inf'))
        return dfs(0, 0, 0)