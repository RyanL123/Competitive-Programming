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

const int MM = 2e5+5;
int a[MM], req[MM], cur[MM];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K, R;
    cin >> N >> K >> R;
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0, b, q; i < R; i++) {
        cin >> b >> q;
        req[b] = q;
    }
    int cnt = 0, ans = inf;
    for (int l = 0, r = 0; r < N; r++) {
        if (++cur[a[r]] == req[a[r]]) cnt++;
        while (l <= r && cur[a[l]] > req[a[l]]) {
            cur[a[l]]--, l++;
        }
        if (cnt >= R) ans = min(ans, r-l+1);
    }
    if (ans == inf) cout << "impossible\n";
    else cout << ans << '\n';
}