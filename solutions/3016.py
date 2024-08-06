class Solution:
    def minimumPushes(self, word: str) -> int:
        c=Counter(word)
        rt=0
        for i, (letter, freq) in enumerate(c.most_common()):
            rt+=freq*(i//8+1)
        return rt