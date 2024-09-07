# 1367. Linked List in Binary Tree
class Solution:
    def isSubPath(self, head: Optional[ListNode], root: Optional[TreeNode]) -> bool:
        def dfs(head, root):
            if head is None:
                return True
            if root is None or head.val!=root.val:
                return False
            return dfs(head.next, root.left) or dfs(head.next, root.right)

        if not root:
            return False
        return dfs(head, root) or self.isSubPath(head, root.left) or self.isSubPath(head, root.right)