# 2196. Create Binary Tree From Descriptions
class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        nodes={}
        is_child=set()
        for (parent, child, isLeft) in descriptions:
            if parent not in nodes:
                nodes[parent]=TreeNode(parent)
            if child not in nodes:
                nodes[child]=TreeNode(child)

            is_child.add(child)
            
            if isLeft==1:
                nodes[parent].left=nodes[child]
            else:
                nodes[parent].right=nodes[child]
    
        for node in nodes:
            if node not in is_child:
                return nodes[node]