# same tree
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if (p==None and q!=None) or (q==None and p!=None):
            return False
        if not p and not q:
            return True
        return (p.val==q.val and self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right))