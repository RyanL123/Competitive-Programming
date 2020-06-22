
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

int pfx[1005], d[1005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vii v;
    for (int i = 1; i <= n; i++) {
        int t, s;
        cin >> t >> s;
        v.eb(s, t);
    }
    srt(v);
    for (int i = 1; i <= n; i++){
        pfx[i] = pfx[i - 1] + v[i-1].second;
        d[i] = v[i-1].first;
    }
    int ans = inf;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, d[i] - pfx[i]);
    }
    cout << (ans >= 0 ? ans : -1) << '\n';
}
