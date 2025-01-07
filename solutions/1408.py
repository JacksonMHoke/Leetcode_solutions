# 1408. String Matching in an Array
class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        return [word for word in words if any([word in w and word!=w for w in words])]