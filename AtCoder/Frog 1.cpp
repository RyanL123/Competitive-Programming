#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    int n, input;
    cin >> n;
    int dp[n+10];
    int cost[n+10];

    for (int i = 1; i <= n; i++){
        cin >> input;
        cost[i] = input;
    }
    dp[1] = 0;
    dp[2] = abs(cost[2]-cost[1]);
    for (int i = 3; i <= n; i++){
        dp[i] = min(abs(cost[i]-cost[i-1]) + dp[i-1], abs(cost[i]-cost[i-2]) + dp[i-2]);
    }
    cout << dp[n];
}