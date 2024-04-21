# 1971. Find if Path Exists in Graph
class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        adj_list=[[] for i in range(n)]
        for edge in edges:
            adj_list[edge[0]].append(edge[1])
            adj_list[edge[1]].append(edge[0])
        visited=[False for i in range(n)]
        def dfs(i):
            nonlocal visited
            visited[i]=True
            if i==destination:
                return True
            rt=False
            for edge in adj_list[i]:
                if not visited[edge] and dfs(edge):
                    return True
            return False
        return dfs(source)