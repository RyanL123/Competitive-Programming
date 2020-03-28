#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef long long ll;
typedef unsigned long long ull;
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define inf INT_MAX

int dp[160][310][110];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int m, u, r;
    cin >> m >> u >> r;
    vector<tuple<int, int, int>> obj;
    for (int i = 0; i < r; i++){
        int v, t, f;
        cin >> v >> t >> f;
        obj.pb(make_tuple(v, t, f));
    }
    for (int i = 1; i <= r; i++){
        for (int j = 0; j <= m; j++){
            for (int k = 0; k <= u; k++){
                tuple<int, int, int> tup = obj[i-1];
                int val = get<0>(tup);
                int time = get<1>(tup);
                int food = get<2>(tup);
                if (time <= j && food <= k){
                    int take = dp[i-1][j-time][k-food] + val;
                    int noTake = dp[i-1][j][k];
                    dp[i][j][k] = max(take, noTake);
                }
                else {
                    dp[i][j][k] = dp[i-1][j][k];
                }
            }
        }
    }
    cout << dp[r][m][u];
}
