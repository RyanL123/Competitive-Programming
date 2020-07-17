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
    while (t--){
        int n, k;
        ll mx = 0;
        cin >> n >> k;
        vi v;
        map<ll, ll> m;
        for (ll i = 0, x; i < n; i++) {
            cin >> x;
            if (x%k==0) continue;
            m[k-x%k]++;
            mx = max(mx, m[k-x%k]);
        }
        ll ans = 0;
        for (pair<ll, ll> p : m){
            if (p.second == mx) {
                ans = k*(p.second-1) + p.first + 1;
            }
        }
        cout << ans << '\n';
    }
}