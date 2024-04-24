# 1137. N-th Tribonacci Number
class Solution:
    def tribonacci(self, n: int) -> int:
        dp=[0]*(n+3)
        dp[0]=1
        for i in range(3,n+3):
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3]
        return dp[-1]