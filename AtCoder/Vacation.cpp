#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <tuple>

using namespace std;

int dp[3][100010];
int main() {
    int n, a, b, c;
    cin >> n;
    tuple<int, int, int> activities[n];
    for (int i = 0; i < n; i++){
        cin >> a >> b >> c;
        activities[i] = make_tuple(a, b, c);
    }
    dp[0][1] = get<0>(activities[0]);
    dp[1][1] = get<1>(activities[0]);
    dp[2][1] = get<2>(activities[0]);
    for (int i = 2; i <= n; i++){
        for (int j = 0; j < 3; j++){
            int val0 = get<0>(activities[i-1]);
            int val1 = get<1>(activities[i-1]);
            int val2 = get<2>(activities[i-1]);
            if (j == 0){
                dp[j][i] = max(dp[1][i-1] + val0, dp[2][i-1] + val0);
            }
            else if (j == 1) {
                dp[j][i] = max(dp[0][i-1] + val1, dp[2][i-1] + val1);
            }
            else {
                dp[j][i] = max(dp[0][i-1] + val2, dp[1][i-1] + val2);
            }
        }
    }
    cout << max(dp[0][n], max(dp[1][n], dp[2][n]));
}
