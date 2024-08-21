# 664. Strange Printer
class Solution:
    def strangePrinter(self, s: str) -> int:
        temp=""+s[0]
        for c in s:
            if temp[-1]!=c:
                temp+=c
        s=temp
        print(s)
        @lru_cache(None)
        def helper(start, end, prev):
            if start>end:
                return 0
            if start==end:
                return prev!=s[start]
            rt=(s[start]!=prev)+helper(start+1, end, prev)
            for i in range(start+2, end+1):
                if s[i]==s[start]:
                    rt=min(rt, 1+helper(start+1, i-1, s[start])+helper(i+1, end, prev))
            return rt
        return int(helper(0, len(s)-1, '.'))