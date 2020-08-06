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
        int n;
        cin >> n;
        int a[n+1], b[n+1], mna = inf, mnb = inf;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mna = min(mna, a[i]);
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            mnb = min(mnb, b[i]);
        }
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == mna) ans += b[i]-mnb;
            else if (b[i] == mnb) ans += a[i]-mna;
            else {
                int mn = min(a[i]-mna, b[i]-mnb);
                ans += mn;
                a[i] -= mn, b[i] -= mn;
                ans += a[i]-mna, ans += b[i]-mnb;
            }
        }
        cout << ans << '\n';
    }
}