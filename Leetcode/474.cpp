class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int one[605], zero[605], dp[105][105][605];
        memset(one, 0, sizeof(one));
        memset(zero, 0, sizeof(zero));
        for (int i = 0; i < strs.size(); i++) {
            for (int j = 0; j < strs[i].size(); j++) {
                one[i] += strs[i][j] == '1';
                zero[i] += strs[i][j] == '0';
            }
        }
        memset(dp, 0, sizeof(dp));
        int ret = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k < strs.size(); k++) {
                    if (i >= one[k] && j >= zero[k]) {
                        dp[i][j][k] = max(dp[i][j][k], 1);
                    }
                    if (i-one[k] >= 0 && j-zero[k] >= 0 && k >= 1) {
                        dp[i][j][k] = max(dp[i-one[k]][j-zero[k]][k-1]+1, dp[i][j][k]);
                        dp[i][j][k] = max(dp[i][j][k-1], dp[i][j][k]);
                    }
                    else if (k >= 1) {
                        dp[i][j][k] = max(dp[i][j][k-1], dp[i][j][k]);
                    }
                    ret = max(ret, dp[i][j][k]);
                }
            }
        }
        return ret;
    }
};