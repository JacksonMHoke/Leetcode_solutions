# 974. Subarray Sums Divisible by K
class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        remainder=defaultdict(lambda: 0)
        remainder[0]=1
        prefix, rt=0, 0
        for num in nums:
            prefix=(prefix+num)%k
            rt+=remainder[prefix]
            remainder[prefix]+=1
        return rt