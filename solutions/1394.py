# 1394. Find Lucky Integer in an Array
class Solution:
    def findLucky(self, arr: List[int]) -> int:
        return max([val for val, freq in Counter(arr).items() if val==freq]+[-1])