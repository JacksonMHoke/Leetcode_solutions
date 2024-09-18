# 179. Largest Number
class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        return ''.join(sorted([str(x) for x in nums], key=functools.cmp_to_key(lambda x,y: 1 if x+y>y+x else -1), reverse=True)).lstrip('0') or '0'