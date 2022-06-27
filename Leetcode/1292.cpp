class Solution {
public:
    int pfx[305][305];
    int check(vector<vector<int>> &mat, int sz) {
        int m = mat.size(), n = mat[0].size(), ret = INT_MAX;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i + sz < m && j + sz < n) {
                    int sum = pfx[i+sz+1][j+sz+1] - pfx[i+sz+1][j] - pfx[i][j+sz+1] + pfx[i][j];
                    ret = min(ret, sum);
                }
            }
        }
        return ret;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size(), l = 1, r = 300, ret = 0;
        memset(pfx, 0, sizeof(pfx));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pfx[i][j] = pfx[i][j-1] + mat[i-1][j-1];
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pfx[i][j] += pfx[i-1][j];
            }
        }
        while (l <= r) {
            int m = (l+r)/2;
            if (check(mat, m) <= threshold) {
                ret = max(ret, m+1);
                l = m+1;
            }
            else r = m-1;
        }
        return ret;
    }
};