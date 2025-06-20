# 3443. Maximum Manhattan Distance After K Changes
class Solution:
    def maxDistance(self, s: str, k: int) -> int:
        mp={'S' : 0, 'N' : 1, 'W' : 2, 'E' : 3}
        dirs=[0 for i in range(4)]
        x,y,rt=0,0,0
        for c in s:
            dirs[mp[c]]+=1
            y+=mp[c]*2-1 if mp[c]<2 else 0
            x+=(mp[c]-2)*2-1 if mp[c]>1 else 0
            rt=max(rt, abs(x)+abs(y)+2*min(k, ((y<0)*dirs[1]+(y>0)*dirs[0]+(y==0)*max(dirs[0], dirs[1]))+((x<0)*dirs[3]+(x>0)*dirs[2]+(x==0)*max(dirs[2], dirs[3]))))
        return rt