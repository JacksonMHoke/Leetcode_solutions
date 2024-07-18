# 1530. Number of Good Leaf Nodes Pairs
class Solution:
    def countPairs(self, root: TreeNode, distance: int) -> int:
        rt=0
        def dfs(root):
            if not root:
                return []
            if root.left==root.right:
                return [1]
            
            leftDists=dfs(root.left)
            rightDists=dfs(root.right)

            nonlocal rt
            nonlocal distance
            l=0
            for r in range(len(rightDists)-1, -1, -1):
                while l<len(leftDists) and leftDists[l]<=distance-rightDists[r]:
                    l+=1
                rt+=l
            
            return sorted(map(lambda x:x+1, leftDists+rightDists))
        dfs(root)
        return rt
