# 2097. Valid Arrangement of Pairs
class Solution:
    def validArrangement(self, pairs: List[List[int]]) -> List[List[int]]:
        adj_list=defaultdict(list)
        net_edges=defaultdict(int)
        curr=[]
        for start, end in pairs:
            adj_list[start].append(end)
            net_edges[start]+=1
            net_edges[end]-=1
        
        root=pairs[0][0]
        for key, val in net_edges.items():
            if val==1:
                root=key

        def construct_path(i):
            while len(adj_list[i])>0:
                nei=adj_list[i][-1]
                adj_list[i].pop()
                construct_path(nei)
                curr.append([i,nei])
        construct_path(root)
        return list(reversed(curr))