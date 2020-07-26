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

int N, L, R, K, a[105], dp[101][10005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> L >> R >> K;
    for (int i = 1; i <= N; i++) cin >> a[i];
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = R-L+1; j > 0; j--) {
            int cost = abs(i - (L+j-1));
            for (int k = cost; k <= K; k++) {
                dp[j][k] = min(dp[j][k], dp[j-1][k-cost] + a[i]);
            }
        }
    }
    int ans = inf;
    for (int i = 0; i <= K; i++) ans = min(ans, dp[R-L+1][i]);
    cout << ans << '\n';
}