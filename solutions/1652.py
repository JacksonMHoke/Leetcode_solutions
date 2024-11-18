# 1652. Defuse the Bomb
class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        n=len(code)
        rt=[0 for i in range(n)]
        if k==0:
            return rt
        windowSum=sum(code[:k]) if k>0 else sum(code[k:])
        rng=range(n-1, -1, -1) if k>0 else range(n)
        for i in rng:
            rt[i]=windowSum
            windowSum+=code[i]-code[(i+k)%n]
        return rt