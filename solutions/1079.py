# 1079. Letter Tile Possibilities
class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        c=Counter(tiles)
        freqs=[[key, val] for key, val in c.items()]
        n=len(tiles)
        def backtrack(curr):
            if len(curr)==n:
                return 1
            sm=1
            for i in range(len(freqs)):
                if freqs[i][1]>0:
                    freqs[i][1]-=1
                    sm+=backtrack(curr+freqs[i][0])
                    freqs[i][1]+=1
            return sm
        return backtrack("")-1
