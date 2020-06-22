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
    int n, q;
    cin >> n >> q;
    vi v;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.pb(x);
    }
    srt(v);
    for (int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        cout << upper_bound(all(v), r) - lower_bound(all(v), l) << '\n';
    }
}
