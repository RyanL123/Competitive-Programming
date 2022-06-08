class Solution {
public:
    // dp[i][j] = LCS of substring text1 (0, i) and text2 (0, j)
    // answer is in dp[n-1][m-1]
    // dp[0][0] = 1 if text1[0] == text2[0]
    // dp[0][j] = 1 if text1[0] = any character in text2
    // dp[i][0] = 1 if text2[0] = any character in text1
    // dp[i][j] = 1 + dp[i-1][j-1] if s1[i] == s2[j]
    // dp[i][j] = max(dp[i-1][j], dp[i][j-1]) otherwise
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        int dp[1005][1005];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int cur = dp[i-1][j-1] + (text1[i-1] == text2[j-1]);
                cur = max(cur, max(dp[i-1][j], dp[i][j-1]));
                dp[i][j] = cur;
            }
        }
        return dp[n][m];
    }
};