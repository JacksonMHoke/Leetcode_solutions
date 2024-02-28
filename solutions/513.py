# Find Bottom Left Tree Value
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        q = deque()
        q.append([root, 0])
        leftmost = 0
        depth = -1
        while len(q)>0:
            curr_node, curr_depth = q[0][0], q[0][1]
            q.popleft()
            if (curr_depth>depth):
                depth=curr_depth
                leftmost=curr_node.val

            if (curr_node.left):
                q.append([curr_node.left, curr_depth+1])
            if (curr_node.right):
                q.append([curr_node.right, curr_depth+1])
        return leftmost