# 2326. Spiral Matrix IV
class Solution:
    def spiralMatrix(self, m: int, n: int, head: Optional[ListNode]) -> List[List[int]]:
        dirs=[0,1,0,-1]
        i,j,d=0,0,0
        rt=[[-1]*n for _ in range(m)]
        while head:
            rt[i][j]=head.val
            head=head.next

            if (not 0<=i+dirs[d]<m) or (not 0<=j+dirs[(d+1)%4]<n) or rt[i+dirs[d]][j+dirs[(d+1)%4]]!=-1:
                d=(d+1)%4
            i+=dirs[d]
            j+=dirs[(d+1)%4]
        return rt
