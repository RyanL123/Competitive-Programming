class Solution {
public:
    int dp[105]; // dp[i] = ways to decode substring s(i, n-1);
    int rec(string &s, int i) {
        if (dp[i] != -1) return dp[i];
        if (s[i] == '0') return dp[i] = 0;
        if (i == s.size()) return dp[i] = 1;
        int ret = rec(s, i+1);
        if (i < s.size()-1 && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))) ret += rec(s, i+2);
        return dp[i] = ret;
    }
    int numDecodings(string s) {
        if (s.empty()) return 0;
        memset(dp, -1, sizeof(dp));
        rec(s, 0);
        return dp[0];
    }
};