# 2176. Count Equal and Divisible Pairs in an Array
class Solution:
    def countPairs(self, nums: List[int], k: int) -> int:
        return sum([1 for i in range(len(nums)) for j in range(i+1, len(nums)) if nums[i]==nums[j] and i*j%k==0])