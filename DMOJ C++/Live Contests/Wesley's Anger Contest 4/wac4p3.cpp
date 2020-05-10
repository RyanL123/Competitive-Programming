#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define srt(x) sort(x.begin(), x.end())
#define inf 0x3f3f3f3f

int N, S, x[15], y[15], vx[15], vy[15];
ld dp[1<<15][15], ans = 1.0e20;

ld f(ld mx, ld my, ld t0, int i){
    ld dx = x[i] + vx[i]*t0 - mx, dy = y[i] + vy[i]*t0 - my;
    ld A = S*S - vx[i]*vx[i] - vy[i]*vy[i];
    ld B = -2*(dx*vx[i] + dy*vy[i]);
    ld C = -dx*dx - dy*dy;
    return (-B + sqrt(B*B - 4*A*C))/(2*A);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> S;
    fill_n(dp[0], 15*(1<<15), 1.0e20);
    for (int i = 0; i < N; i++){
        cin >> x[i] >> y[i] >> vx[i] >> vy[i];
        dp[1<<i][i] = f(0, 0, 0, i);
    }
    for (int mask = 1; mask < (1<<N); mask++){
        for (int i = 0; i < N; i++){
            if (!(mask & (1<<i))) continue;
            for (int j = 0; j < N; j++){
                if (mask & (1<<j)) continue;
                ld mx = dp[mask][i]*vx[i] + x[i];
                ld my = dp[mask][i]*vy[i] + y[i];
                dp[mask|(1<<j)][j] = min(dp[mask|(1<<j)][j], dp[mask][i] + f(mx, my, dp[mask][i], j));
            }
        }
    }
    int mask = (1<<N)-1;
    for (int i = 0; i < N; i++) ans = min(ans, dp[mask][i]);
    cout << fixed << setprecision(9) << ans << '\n';
}