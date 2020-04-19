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

ll dp[5005][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, H;
    cin >> N >> H;
    for (int i = 1; i <= N; i++) {
        int g, h, q, t;
        cin >> g >> h >> q >> t;
        for (int j = 1; j <= H; j++){
            ll op1 = 0, op2 = 0;
            if (j >= h) op1 = dp[j-h][0] + g;
            if (j >= t) op2 = dp[j-t][1] + q;
            dp[j][1] = max(op1, op2);
        }
    }
    cout << dp[H][1];
}
