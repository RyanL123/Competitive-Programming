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

const int MM = 1e5+5;
ll a[MM], d[MM];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0, l, r; i < q; i++){
        cin >> l >> r;
        d[r+1]--;
        d[l]++;
    }
    for (int i = 1; i <= n; i++){
        d[i] += d[i-1];
    }
    sort(a, a+n);
    sort(d+1, d+n+1);
    ll ans = 0;
    for (int i = 0; i < n; i++){
        ans += d[i+1]*a[n-i-1];
    }
    cout << ans << "\n";
}