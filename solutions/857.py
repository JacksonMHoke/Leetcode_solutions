# 857. Minimum Cost to Hire K Workers
class Solution:
    def mincostToHireWorkers(self, quality: List[int], wage: List[int], k: int) -> float:
        rq=sorted([(w/q, q) for q, w in zip(quality, wage)])
        heap=[]
        heapify(heap)
        quality_sum=0
        rt=2**63
        for ratio, q in rq:
            heappush(heap, -q)
            quality_sum+=q
            while len(heap)>k:
                quality_sum-=-heap[0]
                heappop(heap)
            
            if len(heap)==k:
                rt=min(rt, quality_sum*ratio)
        return rt