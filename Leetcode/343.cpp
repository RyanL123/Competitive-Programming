class Solution {
public:
    int dp[60];
    int helper(int n) {
        if (dp[n] != -1) return dp[n];
        int mx = 0;
        for (int i = 1; i < n; i++) {
            mx = max(mx, i * helper(n-i));
            mx = max(mx, i * (n-i));
        }
        return dp[n] = mx;
    }
    int integerBreak(int n) {
        memset(dp, -1, sizeof(dp));
        dp[1] = 1;
        return helper(n);
    }
};