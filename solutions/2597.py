# 2597. The Number of Beautiful Subsets
# heavy inspiration from lee
class Solution:
    def beautifulSubsets(self, nums: List[int], k: int) -> int:
        counter=[Counter() for i in range(k)]
        for num in nums:
            counter[num%k][num]+=1
        rt=1
        for i in range(k):
            prev, dp0, dp1=0, 1, 0
            for num in sorted(counter[i]):
                if prev+k==num:
                    dp0, dp1=dp0+dp1, dp0*(2**counter[i][num]-1)
                else:
                    dp0, dp1=dp0+dp1, (dp0+dp1)*(2**counter[i][num]-1)
                prev=num
            rt*=dp0+dp1
        return rt-1