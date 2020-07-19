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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        ll l, r, m;
        cin >> l >> r >> m;
        ll d = r-l;
        for (ll a = l; a <= r; a++) {
            ll np = (m+d)/a;
            if (np > 0 && np * a >= m-d && np * a <= m+d) {
                ll diff = m-np*a;
                if (diff >= 0) cout << a << ' ' << r << ' ' << r-diff << '\n';
                else cout << a << ' ' << l << ' ' << l+abs(diff) << '\n';
                break;
            }
        }
    }
}