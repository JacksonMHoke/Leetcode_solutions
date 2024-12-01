# 1346. Check If N and Its Double Exist
class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        c=Counter(arr)
        return next((x for x in arr if c[x*2]-(x==0)>0), None) is not None