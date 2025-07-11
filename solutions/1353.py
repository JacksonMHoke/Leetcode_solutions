# 1353. Maximum Number of Events That Can Be Attended
class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        rt, start, prev=0, 0, 0
        events=sorted(events)
        events.append([int(1e6), int(1e6)])
        heap=[]
        for [s, e] in events:
            while len(heap)>0 and prev<s:
                if prev<=heap[0]:
                    prev+=1
                    rt+=1
                heappop(heap)
            prev=s
            heappush(heap, e)
        return rt