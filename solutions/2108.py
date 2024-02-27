# Find first palindromic string in array
class Solution:
    def firstPalindrome(self, words: List[str]) -> str:
        return next((x for x in words if x==x[::-1]), "")