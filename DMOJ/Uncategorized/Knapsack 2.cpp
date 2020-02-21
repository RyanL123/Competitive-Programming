#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef long long ll;
typedef unsigned long long ull;
#define pb(a, b) push_back(a, b)
#define eb(a, b) emplace_back(a, b)
#define inf INT_MAX

ll dp[110][100010];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, w;
    cin >> n >> w;
    int weight[n];
    int val[n];
    for (int i = 0; i < n; i++){
        cin >> weight[i] >> val[i];
    }
    for (int i = 0; i <= n; i++){
        for (int j = 1; j <= 100000; j++){
            dp[i][j] = 10000000000;
        }
    }
    // Items taken
    for (int i = 1; i <= n; i++){
        // Value of j
        for (int j = 1; j <= 100000; j++){
            ll notTake = dp[i-1][j];
            ll take;
            if (val[i-1] <= j){
                take = weight[i-1] + dp[i-1][j-val[i-1]];
            }
            else {
                dp[i][j] = notTake;
                continue;
            }
            dp[i][j] = min(notTake, take);
        }
    }
    int maxVal = 0;
    for (int i = 0; i <= 100000; i++){
        if (dp[n][i] <= w && i > maxVal){
            maxVal = i;
        }
    }
    cout << maxVal << endl;
}