# 514. Freedom Trail
class Solution:
    def findRotateSteps(self, ring: str, key: str) -> int:
        n=len(ring)
        m=len(key)
        @lru_cache(None)
        def backtrack(i, j):
            if j>=m:
                return 0
            rt=2**32
            left=right=True
            k=0
            while k<n and (left or right):
                if right and ring[(i+k)%n]==key[j]:
                    rt=min(rt, k+1+backtrack((i+k)%n, j+1))
                    right=False
                if left and ring[(i-k)%n]==key[j]:
                    rt=min(rt, k+1+backtrack((i-k)%n, j+1))
                    left=False
                k+=1
            return rt

        return backtrack(0, 0)