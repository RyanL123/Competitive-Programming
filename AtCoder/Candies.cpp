#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define srt(x) sort(x.begin(), x.end())
#define all(x) x.begin(), x.end()
#define inf 0x3f3f3f3f

const int MM = 1e5+5, MOD = 1e9+7;
ll a[MM], dp[100][MM], psa[100][MM], n, k; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i <= n; i++){
        dp[i][0] = 1;
        psa[i][1] = 1;
    }
    for (int i = 1; i <= k+1; i++){
        psa[0][i] = 1;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= k; j++){
            ll mn = min(a[i], (ll)j);
            dp[i][j] = (psa[i-1][j+1] - psa[i-1][j-mn])%MOD;
            psa[i][j+1] = psa[i][j] + dp[i][j];
        }
    }
    cout << dp[n][k]%MOD << '\n';
}