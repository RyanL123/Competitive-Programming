class Solution {
public:
    bool valid(int m, int n, int r, int c) {
        return r < m && r >= 0 && c < n && c >= 0;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int time[m][n];
        queue<pair<int, int>> q;
        memset(time, 0, sizeof(time));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) q.push({i, j});
                else time[i][j] = 0x3f3f3f3f;
            }
        }
        int dir[] = {0, -1, 0, 1, 0};
        while (!q.empty()) {
            int r = q.front().first, c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int dr = r+dir[i], dc = c+dir[i+1];
                if (!valid(m, n, dr, dc) || grid[dr][dc] != 1 || time[dr][dc] != 0x3f3f3f3f) continue;
                time[dr][dc] = time[r][c]+1;
                q.push({dr, dc});
            }
        }
        int ret = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) ret = max(ret, time[i][j]);
            }
        }
        return ret == 0x3f3f3f3f ? -1 : ret;
    }
};