class Solution {
public:
    // dp[i] = max len of LIS ending with nums[i]
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(2005, 1), cnt(2005, 1);
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[j]+1 > dp[i]) {
                        dp[i] = dp[j]+1;
                        cnt[i] = cnt[j];
                    }
                    else if (dp[j]+1 == dp[i]) {
                        cnt[i] += cnt[j];
                    }
                }
            }
        }
        int mx = 0, ret = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, dp[i]);
        }
        for (int i = 0; i < n; i++) {
            if (dp[i] == mx) {
                ret += cnt[i];
            }
        }
        return ret;
    }
};