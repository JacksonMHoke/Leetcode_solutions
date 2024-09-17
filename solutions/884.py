# 884. Uncommon Words from Two Sentences
class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        c1=Counter(s1.split(' '))
        c2=Counter(s2.split(' '))
        return set([w for w in c1.keys() if c1[w]==1 and c2[w]==0])^set([w for w in c2.keys() if c2[w]==1 and c1[w]==0])