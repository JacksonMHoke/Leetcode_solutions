# 1110. Delete Nodes And Return Forest
class Solution:
    def delNodes(self, root: Optional[TreeNode], to_delete: List[int]) -> List[TreeNode]:
        rt = []
        deleteSet=set(to_delete)
        def dfs(root, isRoot):
            nonlocal rt, deleteSet
            if not root:
                return

            isDeleted=(root.val in deleteSet)
            if not isDeleted and isRoot:
                rt.append(root)

            dfs(root.left, isDeleted)
            dfs(root.right, isDeleted)
            
            if root.left and root.left.val in deleteSet:
                root.left=None
            if root.right and root.right.val in deleteSet:
                root.right=None

        dfs(root, True)
        return rt