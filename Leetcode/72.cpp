class Solution {
public:
    // dp[i][j] = min edit distance of word1(0, i) to word2(0, j)
    // inserting a character in s1 is the same as deleting a character from s2
    int minDistance(string word1, string word2) {
        int dp[505][505];
        memset(dp, 0x3f, sizeof(dp));
        int n = word1.size(), m = word2.size();
        for (int i = 0; i <= n; i++) dp[0][i] = i;
        for (int i = 0; i <= m; i++) dp[i][0] = i;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int cur = dp[i][j];
                if (word2[i-1] == word1[j-1]) cur = min(cur, dp[i-1][j-1]);
                cur = min(cur, dp[i-1][j]+1);
                cur = min(cur, dp[i][j-1]+1);
                cur = min(cur, dp[i-1][j-1]+1);
                dp[i][j] = cur;
            }
        }
        return dp[m][n];
    }
};