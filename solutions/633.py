# 633. Sum of Square Numbers
class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        powers=set()
        i=0
        while i*i<=c:
            powers.add(i*i)
            i+=1
        
        i=0
        while i*i<=c:
            if c-i*i in powers:
                return True
            i+=1
        return False