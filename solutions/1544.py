# 1544. Make The String Great
class Solution:
    def makeGood(self, s: str) -> str:
        diff=abs(ord('a')-ord('A'))
        stack=[]
        for c in s:
            if len(stack)>0 and abs(ord(stack[-1])-ord(c))==diff:
                stack.pop()
            else:
                stack.append(c)
        return "".join(stack)