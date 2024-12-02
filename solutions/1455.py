# 1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence
class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        idx=(' '+sentence).find(' '+searchWord)
        return sentence[:idx].count(' ')+1 if idx!=-1 else -1