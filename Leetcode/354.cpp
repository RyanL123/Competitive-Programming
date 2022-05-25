class Solution {
public:
    static bool cmp(const vector<int> a, const vector<int> &b) {
        return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<int> dp(100005, 0x3f3f3f3f);
        dp[0] = -0x3f3f3f3f;
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), cmp);
        for (int i = 0; i < n; i++) {
            int j = upper_bound(dp.begin(), dp.end(), envelopes[i][1]) - dp.begin();
            if (dp[j-1] < envelopes[i][1]) dp[j] = envelopes[i][1];
        }
        int ret = 0;
        for (int i = 0; i <= n; i++) {
            if (dp[i] < 0x3f3f3f3f) ret = i;
        }
        return ret;
    }
};