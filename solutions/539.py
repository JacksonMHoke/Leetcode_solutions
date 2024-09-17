# 539. Minimum Time Difference
class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        timePoints=sorted(timePoints)
        rt=2**63
        for i in range(len(timePoints)):
            hourDiff=int(timePoints[i][:2])-int(timePoints[i-1][:2])
            minDiff=int(timePoints[i][3:])+60-int(timePoints[i-1][3:])
            if hourDiff<0:
                hourDiff=24-int(timePoints[i-1][:2])+int(timePoints[i][:2])
                rt=min(rt, max(0, hourDiff-1)*60+minDiff)
            elif hourDiff==0:
                minDiff=abs(int(timePoints[i][3:])-int(timePoints[i-1][3:]))
                rt=min(rt, minDiff)
            else:
                rt=min(rt, max(0, hourDiff-1)*60+minDiff)
        return rt