# 416. Partition Equal Subset Sum
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        s=sum(nums)
        if s%2==1:
            return False
        @lru_cache(None)
        def dfs(i, remainder):
            if remainder==0:
                return True
            if remainder<0 or i>=len(nums):
                return False
            return dfs(i+1, remainder-nums[i]) or dfs(i+1, remainder)
        return dfs(0, s//2)