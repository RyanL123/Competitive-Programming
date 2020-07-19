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

int R, C, err[2], mask, dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}, p[14];
ld dp[2][1594323];
string s;

// Decode bitmask to piece positions
void decode(int g[], int mask) {
    int p = R*C-1;
    for (int i = R-1; i >= 0; i--) {
        for (int j = C-1; j >= 0; j--) {
            g[p--] = mask % 3;
            mask /= 3;
        }
    }
}

ld fun(int u, int mask) {
    if (dp[u][mask] >= 0) return dp[u][mask];
    vector<ld> prob;
    int g[14];
    decode(g, mask);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int cur = i*C + j;
            if (g[cur] != u+1) continue;
            for (int k = 0; k < 4; k++) {
                int nr = i + dir[k][0], nc = j + dir[k][1], nxt = nr*C + nc;
                if (nr >= 0 && nr < R && nc >= 0 && nc < C && g[nxt]) {
                    int nmask = mask - g[cur]*p[R*C-cur-1] - g[nxt]*p[R*C-nxt-1] + g[cur]*p[R*C-nxt-1];
                    prob.pb(1 - fun(!u, nmask));
                }
            }
        }
    }
    sort(all(prob), greater<ld>());
    ld ret = 0.0;
    int sz = min((int)prob.size(), err[u]);
    if (sz == 0) return dp[u][mask] = 0.0;
    for (int i = 0; i < sz; i++) ret += prob[i];
    return dp[u][mask] = ret/sz;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> R >> C;
    p[0] = 1;
    for (int i = 1; i < R*C; i++) p[i] = p[i-1]*3;
    fill_n(dp[0], 2*1594323, -1.0);
    for (int i = 0; i < R; i++) {
        cin >> s;
        for (int j = 0; j < C; j++) {
            int val = 0;
            if (s[j] == 'J') val = 1;
            if (s[j] == 'D') val = 2;
            mask = mask*3 + val;
        }
    }
    cin >> err[0] >> err[1];
    cout << fixed << setprecision(3) << fun(0, mask) << '\n';
}