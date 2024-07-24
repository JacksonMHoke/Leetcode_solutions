# 2191. Sort the Jumbled Numbers
class Solution:
    def sortJumbled(self, mapping: List[int], nums: List[int]) -> List[int]:
        str_mapping = dict(zip([str(x) for x in range(10)], [str(x) for x in mapping]))
        def jumble(s):
            nonlocal str_mapping
            nonlocal mx
            rt='0'*(mx-len(s))
            for char in s:
                rt+=str_mapping[char]
            return rt
        nums_str=[str(x) for x in nums]
        mx=len(max(nums_str, key=len))
        jumbled=[jumble(str(x)) for x in nums]
        return [x[1] for x in sorted(zip(jumbled, nums), key=lambda x: x[0])]