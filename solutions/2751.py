# 2751. Robot Collisions
class Solution:
    def survivedRobotsHealths(self, positions: List[int], healths: List[int], directions: str) -> List[int]:
        robotsByPos=sorted(zip(positions, healths, directions, range(len(positions))))
        rightRobots=[]
        leftRobots=[]
        for (pos, hp, d, i) in robotsByPos:
            while d=='L' and len(rightRobots)>0 and hp>=rightRobots[-1][1]:
                hp=hp-1 if hp>rightRobots[-1][1] else 0
                rightRobots.pop()

            if len(rightRobots)<=0 and d=='L' and hp>0:
                leftRobots.append([i, hp])
            elif d=='L' and len(rightRobots)>0 and hp>0:
                rightRobots[-1][1]-=1
            
            if d=='R':
                rightRobots.append([i, hp])
        
        return [x[1] for x in sorted(rightRobots+leftRobots) if x[1]>0]