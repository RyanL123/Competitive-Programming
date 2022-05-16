class Solution {
public:
    void bfs(vector<vector<int>>& grid, int (&mark)[60][60], int (&cnt)[2500], int i, int j, int cur) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        mark[i][j] = cur;
        cnt[cur] = 1;
        int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            int r = q.front().first, c = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int dr = dir[k][0], dc = dir[k][1];
                if (r+dr >= 0 && r+dr < m && c+dc >= 0 && c+dc < n && !mark[r+dr][c+dc] && grid[r+dr][c+dc] == 1) {
                    mark[r+dr][c+dc] = cur;
                    cnt[cur]++;
                    q.push({r+dr, c+dc});
                }
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int mark[60][60];
        int cnt[2500];
        memset(cnt, 0, sizeof(cnt));
        memset(mark, 0, sizeof(mark));
        int cur = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!mark[i][j] && grid[i][j] == 1) {
                    bfs(grid, mark, cnt, i, j, cur);
                    cur++;
                }
            }
        }
        int ret = 0;
        for (int i = 1; i <= cur; i++) ret = max(ret, cnt[i]);
        return ret;
    }
};