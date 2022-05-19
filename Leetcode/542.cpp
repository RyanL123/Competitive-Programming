class Solution {
public:
    bool valid(int m, int n, int i, int j) {
        return i < m && i >= 0 && j < n && j >= 0;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int dir[] = {0, 1, 0, -1, 0};
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) q.push({i, j});
                else mat[i][j] = -1;
            }
        }
        while (!q.empty()) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    cout << mat[i][j] << ' ';
                }
                cout << endl;
            }
            cout << endl;
            int r = q.front().first, c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int dr = r+dir[i], dc = c+dir[i+1];
                if (!valid(m, n, dr, dc) || mat[dr][dc] != -1) continue;
                mat[dr][dc] = mat[r][c]+1;
                q.push({dr, dc});
            }
        }
        return mat;
    }
};