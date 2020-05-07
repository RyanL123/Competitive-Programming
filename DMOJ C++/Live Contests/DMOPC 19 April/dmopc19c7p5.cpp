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

const int MM = 5e5+5;
ll a[MM], p[MM], t[4*MM];

ll query(int n, int l, int r, int tl, int tr){
    if (l > r) return 0;
    if (tl == l && tr == r) return t[n];
    int m = (tl+tr)/2;
    return query(n*2, l, min(r, m), tl, m) + query(n*2+1, max(l, m+1), r, m+1, tr);
}

void incr(int n, int tl, int tr, int pos){
    if (tl > tr) return;
    if (tl == tr) t[n]++;
    else {
        int m = (tl+tr)/2;
        if (pos <= m) incr(n*2, tl, m, pos);
        else incr(n*2+1, m+1, tr, pos);
        t[n] = t[n*2] + t[n*2+1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> p[i];
    ll ans = 0;
    for (int i = 0; i < n; i++){
        ans += query(1, a[p[i]-1]+1, n, 0, n);
        cout << ans << '\n';
        incr(1, 0, n, a[p[i]-1]);
    }
}