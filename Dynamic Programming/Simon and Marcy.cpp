#include <iostream>

using namespace std;

int dp[1010][1010];
int main() {
    int c, m;
    cin >> c >> m;

    //Initialize DP array
    for (int i = 0; i < 1010; i++){
        //0 objects
        dp[0][i] = 0;
        //0 max weight
        dp[i][0] = 0;
    }

    int val[1010];
    int weight[1010];

    //Get input data
    for (int i = 0; i < c; i++){
        cin >> val[i] >> weight[i];
    }

    //DP
    for (int i = 1; i <= c; i++){
        for (int j = 1; j <= m; j++){
            //Object is not taken
            int notTaken = dp[i-1][j];
            int taken;
            //Object can be considered
            if (weight[i-1] <= j){
                taken = dp[i-1][j-weight[i-1]] + val[i-1];
            }
            //Not choice but to leave the object due to weight
            else {
                dp[i][j] = dp[i-1][j];
                continue;
            }
            //Pick the best option out of the two
            dp[i][j] = max(notTaken, taken);
        }
    }
    cout << dp[c][m];
}
