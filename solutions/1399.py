# 1399. Count Largest Group
class Solution:
    def countLargestGroup(self, n: int) -> int:
        dp=[0 for x in range(37)]
        mx=0
        for i in range(1, n+1):
            group=0
            while i>0:
                group+=i%10
                i//=10
            dp[group]+=1
            mx=max(dp[group], mx)
        return sum([1 for freq in dp if freq==mx])