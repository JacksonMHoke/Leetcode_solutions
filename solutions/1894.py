# 1894. Find the Student that Will Replace the Chalk
class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        remainder=k%sum(chalk)
        i=0
        while remainder>0:
            remainder-=chalk[i]
            i+=1
        return i-(remainder<0)