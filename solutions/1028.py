# 1028. Recover a Tree From Preorder Traversal
class Solution:
    def recoverFromPreorder(self, traversal: str) -> Optional[TreeNode]:
        vals=[int(val) for val in re.split(r'-+', traversal)]
        depths=[len(dashes) for dashes in re.split(r'\d+', traversal)]

        def preOrder(root, d, i):
            if i>=len(vals):
                return -1
            if d+1==depths[i+1]:
                root.left=TreeNode(vals[i+1])
                i=preOrder(root.left, d+1, i+1)
            if d+1==depths[i+1]:
                root.right=TreeNode(vals[i+1])
                i=preOrder(root.right, d+1, i+1)
            return i
        rt=TreeNode(vals[0])
        preOrder(rt, 0, 0)
        return rt