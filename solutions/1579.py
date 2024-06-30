# 1579. Remove Max Number of Edges to Keep Graph Fully Traversable
class UnionFind:
    def __init__(self, n):
        self.unions=[[x for x in range(n)], [x for x in range(n)]]
    def find(self, x, person):
        if self.unions[person][x]==x:
            return x
        self.unions[person][x]=self.find(self.unions[person][x], person)
        return self.unions[person][x]
    def union(self, x, y, person):
        self.unions[person][self.find(x, person)]=self.find(self.unions[person][y], person)
    def isTraversable(self):
        for i in range(len(self.unions)):
            group1=self.find(0, i)
            for j in range(len(self.unions[i])):
                if self.find(j, i)!=group1:
                    return False
        return True
                

class Solution:
    def maxNumEdgesToRemove(self, n: int, edges: List[List[int]]) -> int:
        uf = UnionFind(n)
        edges = [[x[0], x[1]-1, x[2]-1] for x in edges]
        rt=0
        for edge in edges:
            if edge[0]==3:
                if uf.find(edge[1], 0)!=uf.find(edge[2], 0):
                    uf.union(edge[1], edge[2], 0)
                    uf.union(edge[1], edge[2], 1)
                else:
                    rt+=1
        
        for edge in edges:
            if edge[0]!=3:
                if uf.find(edge[1], edge[0]-1)!=uf.find(edge[2], edge[0]-1):
                    uf.union(edge[1], edge[2], edge[0]-1)
                else:
                    rt+=1

        if uf.isTraversable():
            return rt
        return -1
        
