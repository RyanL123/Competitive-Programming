#include <iostream>
#include <cstdio>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    int n, k, input;
    cin >> n >> k;
    int dp[n+10];
    int cost[n+10];

    for (int i = 1; i <= n; i++){
        cin >> input;
        cost[i] = input;
    }
    //cost of first 2 stones
    dp[1] = 0;
    dp[2] = abs(cost[2]-cost[1]);

    for (int i = 3; i <= n; i++){
        //loops through k to find most efficient jump, then the current stone to minimum
        int minCost = INT_MAX;
        for (int j = 1; j <= k; j++){
            if (abs(cost[i] - cost[i-j])+dp[i-j] < minCost){
                minCost = abs(cost[i] - cost[i-j])+dp[i-j];
            }
        }
        dp[i] = minCost;
    }
    cout << dp[n];
}