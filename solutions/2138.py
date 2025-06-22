# 2138. Divide a String Into Groups of Size k
class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        return [s[i:i+k]+fill[0]*max(i+k-len(s), 0) for i in range(0, len(s), k)]