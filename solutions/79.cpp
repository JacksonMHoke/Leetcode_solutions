// 79. Word Search
class Solution {
public:
    vector<vector<int>> dirs{{0,1},{0,-1},{1,0},{-1,0}};
    bool helper(vector<vector<char>>& board, string& word, int i, int r, int c) {
        if (i>=word.length()-1 && board[r][c]==word[i])
            return true;
        if (board[r][c]!=word[i])
            return false;
        char old=board[r][c];
        board[r][c]='#';
        for (auto& dir : dirs) {
            int x=r+dir[0], y=c+dir[1];
            if (x<board.size() && x>=0 && y<board[r].size() && y>=0 && helper(board, word, i+1, x, y)) {
                board[r][c]=old;
                return true;
            }
        }
        board[r][c]=old;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i=0; i<board.size(); ++i) {
            for (int j=0; j<board[i].size(); ++j) {
                if (board[i][j]==word[0] && helper(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
};