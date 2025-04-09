# 3375. Minimum Operations to Make Array Values Equal to K
class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        return len(set(nums))-1+(min(nums)!=k) if min(nums)>=k else -1