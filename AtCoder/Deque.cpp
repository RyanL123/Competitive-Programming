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
#define inf 0x3f3f3f3f

ll dp[3010][3010], a[3010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    ll sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0, k = i; k < n; j++, k++){
            ll x = 0, y = 0, z = 0;
            if (j+2 <= k) x = dp[j+2][k];
            if (j+1 <= k-1) y = dp[j+1][k-1];
            if (j <= k-2) z = dp[j][k-2];
            dp[j][k] = max(a[j] + min(x, y), a[k] + min(z, y));
        }
    }
    cout << dp[0][n-1]*2 - sum << '\n';
}