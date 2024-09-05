# 2028. Find Missing Observations
class Solution:
    def missingRolls(self, rolls: List[int], mean: int, n: int) -> List[int]:
        m=len(rolls)
        missing=mean*(n+m)-sum(rolls)
        if (missing<n or missing>n*6):
            return []
        
        num=missing//n
        remainder=missing%n
        return [num+(i<remainder) for i in range(n)]