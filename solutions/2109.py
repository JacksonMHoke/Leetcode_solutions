# 2109. Adding Spaces to a String
class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        return ' '.join([s[i:j] for i, j in zip([None]+spaces, spaces+[None])])