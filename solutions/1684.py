# 1684. Count the Number of Consistent Strings
class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        s=set(allowed)
        return sum(1 for word in words if set(word)<=s)