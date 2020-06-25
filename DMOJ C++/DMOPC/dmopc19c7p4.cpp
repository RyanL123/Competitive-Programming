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
const int MM = 3e5+5, M = 1e9+7;
struct E{
    ll a, b, c, d;
};
struct node {
    int l, r;
    E v;
};
node seg[4*MM];
int N, Q, a[MM];
E join(E x, E y){
    E ret;
    ret.a = (x.a*y.a + x.b*y.c)%M;
    ret.b = (x.a*y.b + x.b*y.d)%M;
    ret.c = (x.c*y.a + x.d*y.c)%M;
    ret.d = (x.c*y.b + x.d*y.d)%M;
    return ret;
}
void build(int l, int r, int rt){
    seg[rt].l = l; seg[rt].r = r;
    if (l == r){
        seg[rt].v = E{a[l], 1, 1, 0};
        return;
    }
    int m = (l+r)/2;
    build(l, m, rt*2); build(m+1, r, rt*2+1);
    seg[rt].v = join(seg[rt*2].v, seg[rt*2+1].v);
}
E query(int l, int r, int rt){
    if (seg[rt].l == l && seg[rt].r == r) return seg[rt].v;
    int m = (seg[rt].l + seg[rt].r)/2;
    if (r <= m) return query(l, r, rt*2);
    else if (l > m) return query(l, r, rt*2+1);
    else return join(query(l, m, rt*2), query(m+1, r, rt*2+1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) cin >> a[i];
    build(1, N, 1);
    while (Q--){
        int l, r;
        cin >> l >> r;
        E ans = query(l ,r, 1);
        cout << ans.a << " " << ans.c << '\n';
    }
}