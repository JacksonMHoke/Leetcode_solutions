# 2678. Number of Senior Citizens
class Solution:
    def countSeniors(self, details: List[str]) -> int:
        return sum(1 for detail in details if int(detail[-4:-2])>60)