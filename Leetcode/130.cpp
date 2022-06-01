class Solution {
public:
    void bfs(vector<vector<char>>& board, int (&mark)[205][205], bool (&valid)[405], int i, int j, int cur) {
        int m = board.size(), n = board[0].size();
        queue<pair<int, int>> q;
        int dir[] = {0, 1, 0, -1, 0};
        q.push({i, j});
        mark[i][j] = cur;
        if (i == 0 || i == m-1 || j == 0 || j == n-1) {
            valid[cur] = false;
        }
        while (!q.empty()) {
            int r = q.front().first, c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int dr = r+dir[i], dc = c+dir[i+1];
                if (dr >= 0 && dr < m && dc >= 0 && dc < n && mark[dr][dc] == 0 && board[dr][dc] == 'O') {
                    mark[dr][dc] = cur;
                    if (dr == 0 || dr == m-1 || dc == 0 || dc == n-1) {
                        valid[cur] = false;
                    }
                    q.push({dr, dc});
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        bool valid[405];
        int m = board.size(), n = board[0].size(), cur = 1, mark[205][205];
        memset(mark, 0, sizeof(mark));
        memset(valid, 1, sizeof(valid));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mark[i][j] == 0 && board[i][j] == 'O') {
                    bfs(board, mark, valid, i, j, cur++);
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mark[i][j] != 0 && valid[mark[i][j]]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};