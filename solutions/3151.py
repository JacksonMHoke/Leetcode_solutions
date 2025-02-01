# 3151. Special Array I
class Solution:
    def isArraySpecial(self, nums: List[int]) -> bool:
        return all([nums[i]%2!=nums[i+1]%2 for i in range(0, len(nums)-1)])