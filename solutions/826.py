# 826. Most Profit Assigning Work
class Solution:
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        mx=0
        i=0
        rt=0
        worker=sorted(worker)
        dp=sorted(zip(difficulty, profit))
        for w in worker:
            while i<len(dp) and dp[i][0]<=w:
                mx=max(mx, dp[i][1])
                i+=1
            rt+=mx
        return rt