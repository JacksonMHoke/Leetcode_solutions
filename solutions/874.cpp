// 874. Walking Robot Simulation
class Solution {
public:
    long long hash(int x, int y) {
        return x+30000ll+(y+30000ll)*60000ll;
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<int> dirs{0, 1, 0, -1};
        unordered_set<long long> obs;
        for (auto& o : obstacles)
            obs.insert(hash(o[0], o[1]));
        int dir=0, x=0, y=0;
        int max_dist=0;
        for (int i=0; i<commands.size(); ++i) {
            if (commands[i]==-1)
                dir=(dir+1)%4;
            else if (commands[i]==-2)
                dir=((dir-1)%4+4)%4;
            else {
                for (int j=0; j<commands[i]; ++j) {
                    x+=dirs[dir];
                    y+=dirs[(dir+1)%4];
                    if (obs.contains(hash(x, y))) {
                        x-=dirs[(dir)%4];
                        y-=dirs[(dir+1)%4];
                        break;
                    }
                }
                max_dist=max(max_dist, x*x+y*y);
            }
        }
        return max_dist;
    }
};