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

const int MM = 6e4+5;

int dp[MM];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    fill_n(dp+1, MM, inf);
    vii obj;
    for (int i = 1; i <= n; i++){
        int v, w;
        cin >> v >> w;
        for (int j = 1; j < MM; j++){
            if (v <= j) dp[j] = min(dp[j], dp[j-v]+w);
        }
    }
    int ans = inf;
    for (int i = m; i < MM; i++){
        ans = min(ans, dp[i]);
    }
    cout << ans << '\n';
}
