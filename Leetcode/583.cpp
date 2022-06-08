class Solution {
public:
    // dp[i][j] = min steps to make word1(0, i) and word2(0, j) the same
    // if word1[i] == word2[j], dp[i][j] = dp[i-1][j-1]
    // if word1[i] != word2[j], dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+2)
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        int dp[505][505];
        for (int i = 0; i <= n; i++) dp[i][0] = i;
        for (int i = 0; i <= m; i++) dp[0][i] = i;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int cur = min(dp[i-1][j-1]+2, min(dp[i-1][j]+1, dp[i][j-1]+1));
                if (word1[i-1] == word2[j-1]) cur = min(cur, dp[i-1][j-1]);
                dp[i][j] = cur;
            }
        }
        return dp[n][m];
    }
};