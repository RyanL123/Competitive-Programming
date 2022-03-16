#include <bits/stdc++.h>
using namespace std;

int deleteAndEarn(vector<int>& nums) {
    int n = nums.size();
    int frq[10005], dp[10005];
    memset(frq, 0, sizeof(frq));
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
        frq[nums[i]]++;
    }
    dp[1] = frq[1];
    for (int i = 2; i <= 10000; i++) {
        dp[i] = max(dp[i-2] + i*frq[i], dp[i-1]);
    }
    return dp[10000];
}

int main() {
}