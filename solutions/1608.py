# 1608 Special Array With X Elements Greater Than or Equal X
class Solution:
    def specialArray(self, nums: List[int]) -> int:
        nums=sorted(nums)
        n=len(nums)
        prev=0
        for i in range(n):
            if nums[i]>=n-i and prev<n-i:
                return n-i
            prev=nums[i]
        return -1