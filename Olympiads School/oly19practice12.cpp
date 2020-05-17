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

const int MM = 2e4+5;
int psa[MM], dp[2][MM], mx[2][MM], pre = 0, cur = 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, K;
    cin >> n >> K;
    for (int i = 1; i <= n; i++){
        cin >> psa[i];
        psa[i] += psa[i-1];
    }
    memset(dp, -0x3f, sizeof(dp));
    memset(mx, -0x3f, sizeof(mx));
    dp[0][0] = mx[0][0] = 0;
    for (int i = 1; i <= n; i++){
        dp[cur][0] = 0;
        for (int k = 1; k <= K; k++){
            dp[cur][k] = max(dp[pre][k], mx[pre][k-1] + psa[i]);
        }
        for (int k = 0; k <= K; k++){
            mx[cur][k] = max(mx[pre][k], dp[cur][k] - psa[i]);
        }
        swap(pre, cur);
    }
    cout << dp[pre][K];
}