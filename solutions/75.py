# 75. Sort Colors
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        start = 0
        end = len(nums)-1
        i = 0
        while i<=end:
            if nums[i]==0:
                nums[start], nums[i] = nums[i], nums[start]
                start+=1
                i=max(start, i)
                continue
            if nums[i]==2:
                nums[end], nums[i] = nums[i], nums[end]
                end-=1
                continue
            i+=1