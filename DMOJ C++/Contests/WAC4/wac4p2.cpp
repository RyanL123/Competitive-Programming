#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define srt(x) sort(x.begin(), x.end())
#define inf 0x3f3f3f3f

// Provinces, Total points
ll dp[5005][5005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, totP = 0;
    vii province;
    cin >> n;
    for (int i = 0; i < n; i++){
        int V, P;
        cin >> V >> P;
        totP += P;
        V = V/2+1;
        province.pb(mp(V, P));
    }
    for (int i = 0; i <= n; i++){
        for (int j = 1; j <= totP; j++){
            dp[i][j] = 10000000000000;
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= totP; j++){
            dp[i][j] = min(dp[i][j], dp[i-1][j]);
            if (province[i-1].second <= j){
                dp[i][j] = min(dp[i-1][j-province[i-1].second] + province[i-1].first, dp[i][j]);
            }
        }
    }
    ll ans = 10000000000000;
    for (int i = totP/2+1; i <= totP; i++){
        ans = min(ans, dp[n][i]);
    }
    cout << ans << "\n";
}