# 945. Minimum Increment to Make Array Unique
class Solution:
    def minIncrementForUnique(self, nums: List[int]) -> int:
        nums_sorted=sorted(nums)
        curr=-1
        rt=0
        for num in nums_sorted:
            if curr>=num:
                rt+=curr-num+1
                curr+=1
            curr=max(curr, num)
        return rt