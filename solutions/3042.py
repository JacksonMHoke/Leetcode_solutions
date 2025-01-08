# 3042. Count Prefix and Suffix Pairs I
class Solution:
    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        return sum([len(words[i])<=len(words[j]) and words[j][:len(words[i])]==words[i] and words[j][-len(words[i]):]==words[i] for i in range(len(words)) for j in range(i+1, len(words))])