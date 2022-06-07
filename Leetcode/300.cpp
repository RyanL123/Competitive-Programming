class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(2505, INT_MAX);
        dp[0] = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int j = upper_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
            if (dp[j-1] < nums[i] && dp[j] >= nums[i]) dp[j] = nums[i];
        }
        int ret = 0;
        for (int i = 1; i <= n; i++) {
            if (dp[i] != INT_MAX) ret = i;
        }
        return ret;
    }
};