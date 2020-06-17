#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define inf 0x3f3f3f3f

const int MOD = 1e9+7, MM = 1e6+5;
int dp[MM];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    dp[0] = 1;
    // All powers of 2 <= n
    for (int i = 0; (1<<i) <= n; i++){
        // Add to the current number num of ways to make the
        // number without the current power of 2
        for (int j = (1<<i); j <= n; j++){
            dp[j] = (dp[j-(1<<i)] + dp[j])%MOD;
        }
    }
    cout << dp[n] << "\n";
}
