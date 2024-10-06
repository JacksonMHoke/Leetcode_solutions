# 1813. Sentence Similarity III
class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        s1=sentence1.split(' ')
        s2=sentence2.split(' ')
        
        if len(s2)>len(s1):
            s1,s2=s2,s1
        
        i,j=0,0
        n,m=len(s1),len(s2)
        while i<m and s1[i]==s2[i]:
            i+=1
        while j<m and s1[n-j-1]==s2[m-j-1]:
            j+=1
        
        return j+i>=m