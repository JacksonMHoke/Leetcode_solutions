# Diameter of a binary tree

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        rt = 0
        def dfs(root):
            nonlocal rt
            if root is None:
                return 0
            left = dfs(root.left)
            right = dfs(root.right)
            rt = max(rt, left+right)

            return max(left, right)+1
        dfs(root)
        return rt