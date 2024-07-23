# 1636. Sort Array by Increasing Frequency
class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        c = Counter(nums)
        rt = []
        for item in sorted(c.items(), key=lambda x: (x[1], -x[0])):
            rt+=[item[0]]*item[1]
        return rt