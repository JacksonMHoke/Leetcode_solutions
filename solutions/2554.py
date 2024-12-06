# 2554. Maximum Number of Integers to Choose From a Range I
class Solution:
    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:
        isBanned=set(banned)
        cnt=0
        curr=0
        for i in range(1,n+1):
            if i not in isBanned:
                curr+=i
                cnt+=1
            if curr>maxSum:
                cnt-=1
                break
        return cnt