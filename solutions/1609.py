# 1609. Even Odd Tree
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isEvenOddTree(self, root: Optional[TreeNode]) -> bool:
        q = deque()
        q.append(root)
        depth = 0
        while len(q)>0:
            nodes_in_level = len(q)
            previous = q[0].val*((-1)**(depth%2+1))+1 #fancy equation to create dummy value that satisfies decreasing and increasing conditions for both even and odd
            for i in range(nodes_in_level):
                curr = q[0]
                q.popleft()

                if curr.val%2==depth%2 or (depth%2==1 and curr.val>=previous) or (depth%2==0 and curr.val<=previous):
                    return False

                previous = curr.val

                if curr.left:
                    q.append(curr.left)
                if curr.right:
                    q.append(curr.right)
            depth += 1
        return True
                