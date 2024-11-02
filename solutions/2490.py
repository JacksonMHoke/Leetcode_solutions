# 2490. Circular Sentence
class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        sentence=sentence.split(' ')
        return all([sentence[i][0]==sentence[i-1][-1] for i in range(len(sentence))])