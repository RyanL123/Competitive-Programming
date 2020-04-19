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

int dp[101][101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, T;
    cin >> n >> T;
    for (int i = 1; i <= n; i++){
        int l, prevX = 0, prevT = 0;
        cin >> l;
        for (int j = 0; j < l; j++){
            int t, x;
            cin >> t >> x;
            t += prevT;
            x += prevX;
            prevT = t;
            prevX = x;
            for (int k = 1; k <= T; k++){
                dp[i][k] = max(dp[i][k], dp[i-1][k]);
                if (k >= t) dp[i][k] = max(dp[i][k], dp[i-1][k-t] + x);
            }
        }
    }
    cout << dp[n][T];
}
