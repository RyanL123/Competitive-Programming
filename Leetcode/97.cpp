class Solution {
public:
    // dp[i][j] = 1 if s1(0, i) + s2(0, j) is interleaving for s3(0, i+j), 0 otherwise
    bool isInterleave(string s1, string s2, string s3) {
        int dp[105][105];
        memset(dp, 0, sizeof(dp));
        if (s1.size() + s2.size() != s3.size()) return false;
        for (int i = 0; i <= s1.size(); i++) {
            for (int j = 0; j <= s2.size(); j++) {
                if (i == 0 && j == 0) dp[i][j] = 1;
                else if (i == 0) {
                    dp[i][j] = (s2[j-1] == s3[j-1]) && dp[i][j-1];
                }
                else if (j == 0) {
                    dp[i][j] = (s1[i-1] == s3[i-1]) && dp[i-1][j];
                }
                else {
                    dp[i][j] = ((s1[i-1] == s3[i+j-1]) && dp[i-1][j]) || ((s2[j-1] == s3[i+j-1]) && dp[i][j-1]);
                }
            }
        }
        return dp[s1.size()][s2.size()];
    }
};