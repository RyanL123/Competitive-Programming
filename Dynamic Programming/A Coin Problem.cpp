#include <iostream>
#include <climits>

using namespace std;

// Exceeds memory limit. This uses 80M while limit is 32M

// Amount of coins used x Total
// State = minimum amount of coins for total including x amount of coins
int dp[2010][10010];
int main() {
    int n, v, c, l;
    cin >> n >> v;
    int coins[n];
    for (int i = 0; i < n; i++){
        cin >> coins[i];
    }
    for (int i = 0; i < 2010; i++){
        for (int j = 0; j < 10010; j++){
            if (i != 0  && j != 0){
                dp[i][j] = INT_MAX;
            }
        }
    }
    // Amount of coins used
    for (int k = 1; k <= n; k++){
        // Total
        for (int i = 1; i <= 10000; i++){
            // Minimum coin change algorithm under constrains of K
            for (int j = 1; j <= k; j++){
                if (coins[j-1] <= i){
                    // Use the current coin
                    int useCoin = dp[k][i-coins[j-1]]+1;
                    if (useCoin != INT_MAX && useCoin >= 0){
                        if (dp[k][i] < -1){
                            dp[k][i] = INT_MAX;
                        }
                        dp[k][i] = min(useCoin, dp[k][i]);
                        if (dp[k][i] == INT_MAX){
                            dp[k][i] = -1;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < v; i++){
        cin >> c >> l;
        if (dp[l][c] < -1 || dp[l][c] == INT_MAX){
            cout << -1 << endl;
        }
        else {
            cout << dp[l][c] << endl;
        }
    }
}