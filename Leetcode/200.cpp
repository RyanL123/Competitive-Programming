class Solution {
public:
    void bfs(vector<vector<char>>& grid, int i, int j, int cur) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = cur;
        int dir[] = {0, 1, 0, -1, 0};
        while (!q.empty()) {
            int r = q.front().first, c = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int dr = dir[k], dc = dir[k+1];
                if (r+dr >= 0 && r+dr < m && c+dc >= 0 && c+dc < n && grid[r+dr][c+dc] == '1') {
                    grid[r+dr][c+dc] = '2';
                    q.push({r+dr, c+dc});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cur = 2, m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j, cur++);
                }
            }
        }
        return cur-2;
    }
};