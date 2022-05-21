class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[10005];
        memset(dp, 0x3f, sizeof(dp));
        for (int i = 0; i < coins.size(); i++) {
            if (coins[i] <= 10000) dp[coins[i]] = 1;
        }
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i-coins[j] >= 0) {
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
                }
            }
        }
        return dp[amount] == 0x3f3f3f3f ? -1 : dp[amount];
    }
};