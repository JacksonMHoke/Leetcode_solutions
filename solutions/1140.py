# 1140. Stone Game II
class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        n = len(piles)
        suff = [x for x in piles]
        for i in range(n-2, -1, -1):
            suff[i] += suff[i+1]
        from functools import lru_cache
        @lru_cache(None)
        def dfs(m, i):
            if i+2*m>=n:
                return suff[i]
            rt = 0
            for j in range(1, 2*m+1):
                rt = max(rt, suff[i]-dfs(max(j, m), i+j))
            return rt
        return dfs(1, 0)