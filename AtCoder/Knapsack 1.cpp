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

const int MM = 1e5+5;
int pre = 0, cur = 1, N, W; ll dp[2][MM];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> W;
    for (int i = 0; i < N; i++) {
        ll w, v;
        cin >> w >> v;
        for (int j = 0; j <= W; j++) {
            dp[cur][j] = max(dp[pre][j], dp[cur][j]);
            if (w <= j) dp[cur][j] = max(dp[cur][j], dp[pre][j-w]+v);
        }
        swap(pre, cur);
    }
    cout << dp[pre][W] << '\n';
}