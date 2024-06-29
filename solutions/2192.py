# 2192. All Ancestors of a Node in a Directed Acyclic Graph
class Solution:
    def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        rt = [set() for i in range(n)]
        adj_list = [set() for i in range(n)]
        incoming = [0 for i in range(n)]

        for edge in edges:
            adj_list[edge[0]].add(edge[1])
            incoming[edge[1]] += 1
        
        q = deque()

        for i, num_inc in enumerate(incoming):
            if num_inc==0:
                q.append(i)
        
        while len(q)>0:
            curr = q[0]
            q.popleft()
            for child in adj_list[curr]:
                rt[child].update(rt[curr])
                rt[child].add(curr)
                incoming[child]-=1
                if incoming[child]==0:
                    q.append(child)

        return [sorted(list(x)) for x in rt]