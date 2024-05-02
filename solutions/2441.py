# 2441. Largest Positive Integer That Exists With Its Negative
class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        s=set(nums)
        return max([x for x in nums if -x in s], default=-1)