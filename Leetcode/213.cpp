#include <bits/stdc++.h>
using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0]; // 1 house
    int mx = 0;
    int dp[2][n+1];
    memset(dp, 0, sizeof(dp));
    dp[1][0] = nums[0]; // rob first house
    dp[0][1] = nums[0]; // cannot rob second house
    for (int i = 2; i < n-1; i++) {
        dp[1][i] = dp[0][i-1] + nums[i];
        dp[0][i] = max(dp[0][i-1], dp[1][i-1]);
    }
    mx = max(dp[0][n-2], dp[1][n-2]); // cannot rob last house
    memset(dp, 0, sizeof(dp));
    dp[1][1] = nums[1]; // rob second house
    for (int i = 2; i < n; i++) {
        dp[1][i] = dp[0][i-1] + nums[i];
        dp[0][i] = max(dp[0][i-1], dp[1][i-1]);
    }
    mx = max(mx, max(dp[0][n-1], dp[1][n-1]));
    return mx;
}

int main() {
}