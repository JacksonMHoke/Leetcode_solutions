# 1105. Filling Bookcase Shelves
class Solution:
    def minHeightShelves(self, books: List[List[int]], shelfWidth: int) -> int:
        @lru_cache(None)
        def helper(i):
            if i>=len(books):
                return 0
            currHeight=0
            currWidth=0
            rt=2**63
            while i<len(books):
                currWidth+=books[i][0]
                currHeight=max(currHeight, books[i][1])
                if currWidth>shelfWidth:
                    break
                rt=min(rt, currHeight+helper(i+1))
                i+=1
            return rt

        return helper(0)