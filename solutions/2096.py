# 2096. Step-By-Step Directions From a Binary Tree Node to Another
class Solution:
    def getDirections(self, root: Optional[TreeNode], startValue: int, destValue: int) -> str:
        def find(root, val):
            if not root:
                return (False, "")

            if root.val==val:
                return (True, "")

            leftFound, leftPath = find(root.left, val)
            if leftFound:
                return (True, "L"+leftPath)
            
            rightFound, rightPath = find(root.right, val)
            if rightFound:
                return (True, "R"+rightPath)

            return (False, "")

        startPath=find(root, startValue)[1]
        destPath=find(root, destValue)[1]

        i=0
        while i<len(startPath) and i<len(destPath) and startPath[i]==destPath[i]:
            i+=1
        
        return "U"*(len(startPath)-i)+destPath[i:]