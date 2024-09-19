# 241. Different Ways to Add Parentheses
class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        expression=re.split('(\*|\+|\-)', expression)
        n=len(expression)
        rt=[]
        op={'+': (lambda x,y: x+y), '-': (lambda x,y: x-y), '*': (lambda x,y: x*y)}
        @lru_cache(None)
        def helper(i, j):
            if j-i==2:
                return [op[expression[i+1]](int(expression[i]), int(expression[j]))]
            if j-i==0:
                return [int(expression[i])]
            ways=[]
            for k in range(i, j, 2):
                ways+=[op[expression[k+1]](x,y) for x,y in product(helper(i, k), helper(k+2, j))]
            return ways

        return helper(0, n-1)