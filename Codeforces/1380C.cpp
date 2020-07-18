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
        ll n, x;
        cin >> n >> x;
        vi v;
        for (int i = 0, x; i < n; i++) {
            cin >> x;
            v.pb(x);
        }
        srt(v);
        int ptr = n-1, ans = 0, cnt = 1, mn = 0;
        while (ptr >= 0){
            mn = v[ptr];
            cnt = 1;
            while (ptr > 0 && cnt * mn < x) {
                ptr--, cnt++;
                mn = v[ptr];
            }
            if (cnt * mn >= x) ans++;
            ptr--;
        }
        cout << ans << '\n';
    }
}