class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        bool seen[60][60];
        int m = image.size(), n = image[0].size(), color = image[sr][sc];
        memset(seen, 0, sizeof(seen));
        queue<pair<int, int>> q;
        q.push({sr, sc});
        seen[sr][sc] = 1;
        image[sr][sc] = newColor;
        int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            int r = q.front().first, c = q.front().second;
            q.pop(); 
            for (int i = 0; i < 4; i++) {
                int dr = dir[i][0], dc = dir[i][1];
                if (r+dr >= 0 && r+dr < m && c+dc >= 0 && c+dc < n && !seen[r+dr][c+dc] && image[r+dr][c+dc] == color) {
                    seen[r+dr][c+dc] = 1;
                    image[r+dr][c+dc] = newColor;
                    q.push({r+dr, c+dc});
                }
            }
        }
        return image;
    }
};