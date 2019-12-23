#include <iostream>
#include <vector>

using namespace std;

long dp[2][100010];
int main() {
    int n, w;
    cin >> n >> w;

    // Get objects
    int objWeight[101];
    int objVal[101];
    for (int i = 0; i < n; i++){
        cin >> objWeight[i];
        cin >> objVal[i];
    }

    //DP
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= w; j++){
            if (i%2 == 0){
                // Do not take the object
                long notTaken = dp[1][j];
                long taken;
                // Item can be considered
                if (objWeight[i-1] <= j){
                    taken = dp[1][j-objWeight[i-1]] + objVal[i-1];
                }
                else {
                    // Cannot take item
                    dp[0][j] = dp[1][j];
                    continue;
                }
                // Take the most optimal choice
                dp[0][j] = max(taken, notTaken);
            }
            else {
                // Do not take the object
                long notTaken = dp[0][j];
                long taken;
                // Item can be considered
                if (objWeight[i-1] <= j){
                    taken = dp[0][j-objWeight[i-1]] + objVal[i-1];
                }
                else {
                    // Cannot take item
                    dp[1][j] = dp[0][j];
                    continue;
                }
                // Take the most optimal choice
                dp[1][j] = max(taken, notTaken);
            }
        }
    }
    if (n%2 == 0){
        cout << dp[0][w];
    }
    else {
        cout << dp[1][w];
    }
}
