class Solution {
public:
    bool helper(vector<vector<char>>& board, string &word, int ind, int r, int c) {
        if (ind == word.size()-1) return true;
        char cur = board[r][c];
        board[r][c] = '_';
        int dir[] = {0, 1, 0, -1, 0};
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < 4; i++) {
            int dr = r+dir[i], dc = c+dir[i+1];
            if (dr >= 0 && dr < m && dc >= 0 && dc < n && board[dr][dc] == word[ind+1]) {
                if (helper(board, word, ind+1, dr, dc)) return true;
            }
        }
        board[r][c] = cur;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        bool ret = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (helper(board, word, 0, i, j)) return true;
                }
            }
        }
        return false;
    }
};