# 2134. Minimum Swaps to Group All 1's Together II
class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        numOnes=sum(1 for num in nums if num==1)
        currZeros=sum(1 for i in range(-numOnes, 0) if nums[i]==0)
        rt=currZeros
        for i in range(-numOnes, len(nums)-numOnes):
            currZeros+=(nums[i+numOnes]==0)-(nums[i]==0)
            rt=min(rt, currZeros)
        return rt