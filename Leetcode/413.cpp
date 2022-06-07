class Solution {
public:
    // dp[i] = number of arithmetic slices ending at i
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        int dp[5005];
        int n = nums.size();
        memset(dp, 0, sizeof(dp));
        for (int i = 2; i < n; i++) {
            if (nums[i-1] - nums[i-2] == nums[i] - nums[i-1]) dp[i] = 1 + dp[i-1];
        }
        int ret = 0;
        for (int i = 0; i < n; i++) ret += dp[i];
        return ret;
    }
};