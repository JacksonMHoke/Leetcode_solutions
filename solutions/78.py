# 78. Subsets
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        rt=[]
        def backtrack(nums, curr, i):
            nonlocal rt
            rt.append(curr[:])

            for j in range(i, len(nums)):
                curr.append(nums[j])
                backtrack(nums, curr, j+1)
                curr.pop() 
            return
        backtrack(nums, list(), 0)
        return rt