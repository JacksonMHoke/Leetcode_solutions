# 2616. Minimize the Maximum Difference of Pairs
class Solution:
    def minimizeMax(self, nums: List[int], p: int) -> int:
        sorted_nums = sorted(nums)

        def check(target):
            c = 0
            i = 0
            while i<len(sorted_nums)-1:
                if sorted_nums[i+1]-sorted_nums[i]<=target:
                    i += 1
                    c += 1
                if c>=p:
                    return True
                i += 1
            return False

        lo = 0
        hi = sorted_nums[-1]-sorted_nums[0]
        while lo<hi:
            m = (lo+hi)//2
            if check(m):
                hi = m
            else:
                lo = m+1
        return hi