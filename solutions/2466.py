# 2466. Count Ways To Build Good Strings
class Solution:
    def countGoodStrings(self, low: int, high: int, zero: int, one: int) -> int:
        MOD = 1000000007
        dp = [0 for x in range(high+1)]
        dp[0] = 1
        rt = 0
        for i in range(high+1):
            if i-zero>=0:
                dp[i] = (dp[i]+dp[i-zero])%MOD
            if i-one>=0:
                dp[i] = (dp[i]+dp[i-one])%MOD
            if i>=low and i<=high:
                rt = (rt+dp[i])%MOD
        return rt