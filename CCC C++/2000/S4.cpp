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

int dp[5300];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int d, n;
    cin >> d >> n;
    vi v;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        v.pb(x);
    }
    srt(v);
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < 5300; i++) {
        for (int j = 0; j < n; j++) {
            if (i-v[j] < 0) continue;
            dp[i] = min(dp[i], dp[i-v[j]]+1);
        }
    }
    if (dp[d] >= inf) cout << "Roberta acknowledges defeat.\n";
    else cout << "Roberta wins in " << dp[d] << " strokes.\n";
}