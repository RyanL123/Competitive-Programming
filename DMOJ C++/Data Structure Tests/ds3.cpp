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
int a[MM], minSeg[MM*2];
pii seg[MM*2];

pii combine(pii a, pii b) {
    int gcd = __gcd(a.second, b.second);
    int cnt = 0;
    cnt += (a.second == gcd ? a.first : 0);
    cnt += (b.second == gcd ? b.first : 0);
    return {cnt, gcd};
}

void build() {
    for (int i = MM-1; i > 0; i--) {
        minSeg[i] = min(minSeg[i<<1], minSeg[i<<1|1]);
        seg[i] = combine(seg[i<<1], seg[i<<1|1]);
    }
}
void upd(int p, int val) {
    for (p += MM, minSeg[p] = val, seg[p] = {1, val}; p > 1; p >>= 1) {
        minSeg[p>>1] = min(minSeg[p], minSeg[p^1]);
        seg[p>>1] = combine(seg[p], seg[p^1]);
    }
}

int qryMin(int l, int r) {
    int ret = inf;
    for (l += MM, r += MM; l < r; l >>= 1, r >>= 1) {
        if (l&1) ret = min(ret, minSeg[l++]);
        if (r&1) ret = min(ret, minSeg[--r]);
    }
    return ret;
}

pii qryGCD(int l, int r) {
    pii ret = {0, 0};
    for (l += MM, r += MM; l < r; l >>= 1, r >>= 1) {
        if (l&1) ret = combine(ret, seg[l++]);
        if (r&1) ret = combine(ret, seg[--r]);
    }
    return ret;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> minSeg[i+MM];
        seg[i+MM] = {1, minSeg[i+MM]};
    }
    build();
    for (int i = 0; i < m; i++) {
        char op;
        cin >> op;
        if (op == 'C') {
            int x, v;
            cin >> x >> v;
            upd(x-1, v);
        }
        else if (op == 'M') {
            int l, r;
            cin >> l >> r;
            cout << qryMin(l-1, r) << '\n';
        }
        else if (op == 'G'){
            int l, r;
            cin >> l >> r;
            cout << qryGCD(l-1, r).second << '\n';
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << qryGCD(l-1, r).first << '\n';
        }
    }
}