// 773. Sliding Puzzle
class Solution {
public:
    void attempt(unordered_map<string, int>& visited, queue<string>& bfs, string& curr, int dist, int i, int j) {
        swap(curr[i], curr[j]);
        if (!visited.contains(curr)) {
            visited[curr]=dist+1;
            bfs.push(curr);
        }
        swap(curr[i], curr[j]);
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_map<string, int> visited;
        queue<string> bfs;
        string initial="";
        for (auto& row : board)
            for (auto num : row)
                initial+='0'+num;
        bfs.push(initial);
        visited[initial]=0;
        while (!bfs.empty()) {
            string state=bfs.front();
            bfs.pop();
            int dist=visited[state];
            if (state=="123450")
                return visited[state];
            for (int i=0; i<state.length(); ++i) {
                if (state[i]!='0')
                    continue;
                if (i+1<6 && i+1!=3)
                    attempt(visited, bfs, state, dist, i, i+1);
                if (i-1>=0 && i-1!=2)
                    attempt(visited, bfs, state, dist, i, i-1);
                if (i-3>=0)
                    attempt(visited, bfs, state, dist, i, i-3);
                if (i+3<6)
                    attempt(visited, bfs, state, dist, i, i+3);
            }
        }
        return -1;
    }
};