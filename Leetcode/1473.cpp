class Solution {
public:
    int dp[105][105][25];
    int helper(vector<int>& houses, vector<vector<int>>& cost, int target, int ind, int prev, int count) {
        if (dp[ind][count][prev] != -1) return dp[ind][count][prev];
        if (ind == houses.size()) return count == target ? 0 : 0x3f3f3f3f;
        int ret = 0x3f3f3f3f;
        // already painted
        if (houses[ind] != 0) {
            // not the same as last house
            if (houses[ind] != prev) ret = helper(houses, cost, target, ind+1, houses[ind], count+1);
            else ret = helper(houses, cost, target, ind+1, prev, count);
        }
        else {
            // try every color
            for (int j = 0; j < cost[0].size(); j++) {
                int cur = 0;
                if (j+1 != prev) cur = cost[ind][j] + helper(houses, cost, target, ind+1, j+1, count+1);
                else cur = cost[ind][j] + helper(houses, cost, target, ind+1, prev, count);
                ret = min(cur, ret);
            }
        }
        return dp[ind][count][prev] = ret;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp, -1, sizeof(dp));
        int ret = helper(houses, cost, target, 0, 0, 0);
        if (ret == 0x3f3f3f3f) return -1;
        return ret;
    }
};