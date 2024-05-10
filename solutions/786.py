# 786. K-th Smallest Prime Fraction
class Solution:
    def kthSmallestPrimeFraction(self, arr: List[int], k: int) -> List[int]:
        l, r, n = 0, 1, len(arr)
        while True:
            m=l+(r-l)/2
            borders=[bisect.bisect(arr, m*arr[i], hi=i) for i in range(n)]
            curr=sum(borders)
            if curr<k:
                l=m
            elif curr>k:
                r=m
            else:
                return max([[arr[borders[i]-1], arr[i]] for i in range(n) if borders[i]-1>=0], key=lambda x: x[0]/x[1])