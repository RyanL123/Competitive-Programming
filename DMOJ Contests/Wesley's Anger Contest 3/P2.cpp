#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

long long dp[3][1000010];
int main() {
    int d, h;
    cin >> d;
    dp[0][3] = 1;
    dp[1][3] = 1;
    dp[2][3] = 1;
    for (int j = 4; j <= 1000000; j++){
        long long e = (dp[0][j-1]+1)*dp[1][j-1]*dp[2][j-1];
        long long s = dp[0][j-1]*(dp[1][j-1]+1)*dp[2][j-1];
        long long c = dp[0][j-1]*dp[1][j-1]*(dp[2][j-1]+1);
        if (max(e, max(s, c)) == e){
            dp[0][j] = dp[0][j-1]+1;
            dp[1][j] = dp[1][j-1];
            dp[2][j] = dp[2][j-1];
        }
        else if (max(e, max(s, c)) == s){
            dp[1][j] = dp[1][j-1]+1;
            dp[0][j] = dp[0][j-1];
            dp[2][j] = dp[2][j-1];
        }
        else {
            dp[2][j] = dp[2][j-1]+1;
            dp[0][j] = dp[0][j-1];
            dp[1][j] = dp[1][j-1];
        }
    }
    for (int i = 0; i < d; i++){
        cin >> h;
        if (h == 3){
            cout << 1 << endl;
            continue;
        }
        else {
            cout << dp[0][h]*dp[1][h]*dp[2][h] << endl;
        }
    }
}
