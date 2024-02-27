# Cheapest flight with K stops
class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        adj_list=[[] for y in range(n)]
        for f, t, cost in flights:
            adj_list[f].append([t, cost])
        
        heap=[[0, 0, src]]
        heapify(heap)

        min_stops=[n+1 for x in range(n)]
        min_stops[src]=0

        while len(heap)>0:
            cost=heap[0][0]
            num_stops=heap[0][1]
            curr_stop=heap[0][2]

            heappop(heap)
            min_stops[curr_stop]=min(min_stops[curr_stop], num_stops)

            if curr_stop==dst:
                return cost

            if num_stops>k:
                continue
            
            for to, c in adj_list[curr_stop]:
                if min_stops[to]>num_stops+1:
                    heappush(heap, [cost+c, num_stops+1, to])
        return -1