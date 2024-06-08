# 523. Continuous Subarray Sum
class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        prefix={}
        prefix[0]=-1
        s=0
        for i, num in enumerate(nums):
            s=(s+num)%k
            if s in prefix and prefix[s]<i-1:
                return True
            if s not in prefix:
                prefix[s]=i
        return False