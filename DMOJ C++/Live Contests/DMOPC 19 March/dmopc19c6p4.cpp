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
map<int, int> seg[4*MM];
int a[MM];

void merge(int n){
    map<int, int> m;
    for (pii p : seg[n*2]){
        m[p.first] += p.second;
    }
    for (pii p : seg[n*2+1]){
        m[p.first] += p.second;
    }
    seg[n] = m;
}

void build(int n, int l, int r){
    if (l > r) return;
    if (l == r){
        seg[n][0] = 1;
    }
    else {
        int m = (l+r)/2;
        build(n*2, l, m);
        build(n*2+1, m+1, r);
        merge(n);
    }
}

void upd(int n, int l, int r, int pos, int val){
    if (l > r) return;
    if (l == r){
        seg[n][a[pos]]--;
        if (seg[n][a[pos]] == 0) seg[n].erase(a[pos]);
        seg[n][a[pos]+val]++;
        return;
    }
    int m = (l+r)/2;
    if (pos <= m) upd(n*2, l, m, pos, val);
    else upd(n*2+1, m+1, r, pos, val);
    merge(n);
}

int qry(int n, int l, int r, int tl, int tr, int val){
    if (l > r) return 0;
    if (tl == l && tr == r){
        return seg[n][val];
    }
    int m = (tl+tr)/2;
    int left = qry(n*2, l, min(r, m), tl, m, val);
    int right = qry(n*2+1, max(m+1, l), r, m+1, tr, val);
    return left+right;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, Q;
    cin >> N >> Q;
    build(1, 0, N-1);
    while (Q--){
        int q, x, l, r, c;
        cin >> q;
        if (q == 1){
            cin >> x;
            upd(1, 0, N-1, x-1, 1);
            a[x-1]++;
        }
        else if (q == 2){
            cin >> x;
            upd(1, 0, N-1, x-1, -1);
            a[x-1]--;
        }
        else {
            cin >> l >> r >> c;
            cout << qry(1, l-1, r-1, 0, N-1, c) << '\n';
        }
    }
}