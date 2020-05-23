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

const int MM = 2e5+5, m = 1e9+7;
ll f[MM], inv[MM], dp[3005];
vii p;
ll comb(int n, int k){
    return f[n]*inv[k]%m*inv[n-k]%m;
}
ll quick_pow(ll x, int exp){
    if (exp == 0) return 1;
    ll t = quick_pow(x, exp/2);
    t = t*t % m;
    if (exp % 2 == 1) return t*x%m;
    return t;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h, w, n;
    cin >> h >> w >> n;
    f[0] = inv[0] = 1;
    for (int i = 1; i <= h+w; i++){
        f[i] = f[i-1]*i % m;
    }
    inv[h+w] = quick_pow(f[h+w], m-2);
    for (int i = h+w-1; i >= 1; i--){
        inv[i] = (i+1)*inv[i+1]%m;
    }
    for (int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        p.pb({x-1, y-1});
    }
    p.pb({h-1, w-1});
    srt(p);
    for (int i = 0; i < p.size(); i++){
        int x = p[i].first, y = p[i].second;
        dp[i] = comb(x+y, x);
        for (int j = 0; j < i; j++){
            int xj = p[j].first, yj = p[j].second;
            if (yj <= y) dp[i] = (dp[i] - dp[j] * comb(x-xj+y-yj, x-xj)%m + m)%m;
        }
    }
    cout << dp[n] << '\n';
}