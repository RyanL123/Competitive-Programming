#include <bits/stdc++.h>
using namespace std;

int jump(vector<int>& nums) {
    int n = nums.size();
    int dp[n+1];
    memset(dp, 0, sizeof(dp));
    int lst = 0;
    for (int i = 0; i < n; i++) {
        for (int j = lst+1; j <= min(n-1, nums[i]+i); j++) {
            dp[j] = dp[i] + 1;
        }
        lst = max(lst, nums[i]+i);
    }
    return dp[n-1];
}

int main() {
}