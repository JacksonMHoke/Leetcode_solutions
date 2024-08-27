# 1514. Path with Maximum Probability
class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
        heap = []
        explored = set()
        probs = [0 for x in range(n)]
        adjList = [[] for x in range(n)]

        for edge, p in zip(edges, succProb):
            adjList[edge[0]].append((edge[1], p))
            adjList[edge[1]].append((edge[0], p))

        heappush(heap, (-1, start))

        while len(heap)!=0:
            p, node = heap[0]
            heappop(heap)

            if node in explored:
                continue

            explored.add(node)

            if node==end:
                break

            for neighbor, succ in adjList[node]:
                if neighbor in explored or p*succ>=probs[neighbor]:
                    continue
                probs[neighbor] = p*succ
                heappush(heap, (p*succ, neighbor))
        
        return -1*probs[end]