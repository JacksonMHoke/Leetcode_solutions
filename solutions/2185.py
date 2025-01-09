# 2185. Counting Words With a Given Prefix
class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        return sum([pref==w[:len(pref)] for w in words])