class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int dp[300][300];
        memset(dp, 0x3f, sizeof(dp));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                dp[i][j] = triangle[i][j]+dp[i-1][j];
                if (j > 0) dp[i][j] = min(dp[i][j], triangle[i][j]+dp[i-1][j-1]);
            }
        }
        int mn = 0x3f3f3f3f;
        for (int i = 0; i < triangle[triangle.size()-1].size(); i++) {
            mn = min(dp[triangle.size()-1][i], mn);
        }
        return mn;
    }
};