# 1122. Relative Sort Array
class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        c=Counter(arr1)
        rt=[]
        for num in arr2:
            rt=rt+[num]*c[num]
            del c[num]
        for key, value in sorted(c.items()):
            rt=rt+[key]*value
        return rt