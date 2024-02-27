# Find polygon with largest perimeter
class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        s = sorted(nums)
        total = 0
        rt = -1
        for num in s:
            if num<total:
                rt=total+num
            total+=num
        return rt