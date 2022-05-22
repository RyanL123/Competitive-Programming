class Solution {
public:
    int countSubstrings(string s) {
        int dp[1005][1005];
        memset(dp, 0, sizeof(dp));
        int n = s.size();
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        int ret = 0;
        for (int j = 0; j < n; j++) {
            for (int i = 0; i <= j; i++) {
                if (i+1 <= j-1) dp[i][j] = s[i] == s[j] && dp[i+1][j-1];
                else dp[i][j] = s[i] == s[j];
                ret += dp[i][j];
            }
        }
        return ret;
    }
};