# 802. Find Eventual Safe States
class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        states=[0 for i in range(len(graph))]
        def dfs(i):
            if states[i]!=0:
                return states[i]==2
            states[i]=1
            for neighbor in graph[i]:
                if not dfs(neighbor):
                    return False
            states[i]=2
            return True
        
        return [node for node in range(len(graph)) if dfs(node)]