# 648. Replace Words
class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        d=set(dictionary)
        rt=""
        for word in sentence.split():
            curr=""
            flag=False
            for c in word:
                curr+=c
                if curr in d:
                    rt+=curr+" "
                    flag=True
                    break
            if not flag:
                rt+=word+" "
        return rt[0:-1]