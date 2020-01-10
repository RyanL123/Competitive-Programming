#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {
    string dp[2] = {"", ""};
    long n, w;
    cin >> n >> w;

    // Get objects
    long objWeight[101];
    long objVal[101];
    for (int i = 0; i < n; i++){
        cin >> objWeight[i];
        cin >> objVal[i];
    }
    string s(1000000000, ' ');
    dp[0] = s;
    dp[1] = s;

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
                dp[0][j] = (char)max(taken, notTaken);
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
                dp[1][j] = (char)max(taken, notTaken);
            }
        }
    }
    if (n%2 == 0){
        cout << (int)dp[0][w];
    }
    else {
        cout << (int)dp[1][w];
    }
}
