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

int T, n, d[20]; ll dp[20][2520][1<<8], lo, hi;
ll f(int pos, int rem, int mask, bool lmt) {
    ll ret = 0;
    if (!lmt && dp[pos][rem][mask] != -1) return dp[pos][rem][mask];
    if (pos == 0) {
        for (int i = 2; i <= 9; i++) {
            if ((mask & 1<<(i-2)) && rem % i != 0) return 0;
        }
        return 1;
    }
    int up = lmt?d[pos]:9;
    for (int i = 0; i <= up; i++) {
        int nmask = i>=2?mask|1<<(i-2):mask;
        ret += f(pos-1, (rem*10+i)%2520, nmask, lmt && i == d[pos]);
    }
    if (!lmt) return dp[pos][rem][mask] = ret;
    return ret;
}

ll solve(ll x) {
    n = 0;
    for (; x; x /= 10) d[++n] = x%10;
    return f(n, 0, 0, 1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> T;
    while (T--) {
        cin >> lo >> hi;
        cout << solve(hi) - solve(lo-1) << "\n";
    }
}