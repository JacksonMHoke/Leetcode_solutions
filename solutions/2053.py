# 2053. Kth Distinct String in an Array
class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        c=Counter(arr)
        i=0
        for s in arr:
            if c[s]==1:
                i+=1
            if i==k:
                return s
        return ""