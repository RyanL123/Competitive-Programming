class Solution {
public:
    struct E {
        int x, y, w;
    };
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1) return -1;
        int cost[105][105];
        memset(cost, 0x3f, sizeof(cost));
        cost[0][0] = 0;
        queue<E> q;
        q.push({0, 0, 0});
        while (!q.empty()) {
            int x = q.front().x;
            int y = q.front().y;
            int w = q.front().w;
            q.pop();
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (i == 0 && j == 0) continue;
                    if (x+i >= 0 && x+i < n && y+j >= 0 && y+j < n && grid[x+i][y+j] == 0) {
                        if (cost[x+i][y+j] > cost[x][y]+1) {
                            cost[x+i][y+j] = cost[x][y]+1;
                            q.push({x+i, y+j, cost[x+i][y+j]});
                        }
                    }
                }
            }
        }
        return cost[n-1][n-1] == 0x3f3f3f3f ? -1 : cost[n-1][n-1]+1;
    }
};