# 472. Concatenated Words
class Solution:
    def findAllConcatenatedWordsInADict(self, words: List[str]) -> List[str]:
        valid=set(words)
        @lru_cache(None)
        def dfs(word, isFirst):
            if word in valid and not isFirst:
                return True
            for i in range(len(word)):
                if word[:i+1] in valid and dfs(word[i+1:], False):
                    valid.add(word)
                    return True
            return False
        rt=[]
        for word in words:
            if dfs(word, True):
                rt.append(word)
        return rt