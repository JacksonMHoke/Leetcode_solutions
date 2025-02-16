# 1718. Construct the Lexicographically Largest Valid Sequence
class Solution:
    def constructDistancedSequence(self, n: int) -> List[int]:
        seq=[0]*(n*2-1)
        def backtrack(i, used):
            if used==0 or i>=n*2-1:
                return True
            if seq[i]!=0:
                return backtrack(i+1, used)
            x=used
            while x>0:
                curr=n-((x&-x).bit_length()-1)
                if curr==1 or (i+curr<n*2-1 and seq[i+curr]==0):
                    seq[i]=curr
                    if curr>1:
                        seq[i+curr]=curr
                    if backtrack(i+1, used^(x&-x)):
                        return True
                    seq[i]=0
                    if curr>1:
                        seq[i+curr]=0
                x-=x&-x
            return False
        backtrack(0, 2**n-1)
        return seq