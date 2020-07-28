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

const int MM = 5e5+5;
ll a[MM];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, ans = inf, tot = 0;
    cin >> n >> m;
    for (int l = 0, r = 0; r < n; r++) {
        cin >> a[r];
        tot += a[r];
        while (tot >= m) {
            tot -= a[l];
            ans = min(ans, (ll)r-l+1);
            l++;
        }
    }
    cout << (ans==inf?-1:ans) << '\n';
}   