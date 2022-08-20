class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // dp[i][j] = max amount of distance i can travel from station i refueling j times before station i
        // refuel at the previous station => dp[i-1][j-1] + fuel[i-1]
        // don't refuel at the previous station => dp[i-1][j]
        long long dp[505][505]; 
        memset(dp, 0, sizeof(dp));
        int n = stations.size();
        // max i can go from any station without refueling is how much I started with
        for (int i = 0; i <= n; i++) {
            dp[i][0] = startFuel;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i][j] = dp[i-1][j]; // do not refuel
                if (dp[i-1][j-1] >= stations[i-1][0]) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + stations[i-1][1]);
                }
            }
        }
        for (int j = 0; j <= n; j++) {
            if (dp[n][j] >= target) return j;
        }
        return -1;
    }
};