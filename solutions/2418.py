# 2418. Sort the People
class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        return [name for height, name in sorted(zip(heights, names), reverse=True)]