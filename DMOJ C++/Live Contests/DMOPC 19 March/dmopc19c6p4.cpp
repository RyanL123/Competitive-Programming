#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define inf 0x3f3f3f3f

map<int, int> t[2000000];

void combine(int n){
    map<int, int> l = t[n*2];
    map<int, int> r = t[n*2+1];
    map<int, int> m = l;
    for (pii v : r){
        if (m[v.first] == 0) m[v.first] = v.second;
        else m[v.first] += v.second;
    }
    t[n] = m;
}

void build(int n, int l, int r){
    if (l == r){
        t[n][0] = 1;
    }
    else {
        int m = (l+r)/2;
        build(n*2, l, m);
        build (n*2+1, m+1, r);
        combine(n);
    }
}

void increment(int n, int l, int r, int pos){
    if (l > r) return;
    if (l == r){
        int erase = 0;
        for (pii p : t[n]){
            t[n][p.first+1] = 1;
            erase = p.first;
            break;
        }
        t[n].erase(erase);
    }
    else {
        int m = (l+r)/2;
        if (pos <= m) increment(n*2, l, m, pos);
        else increment(n*2+1, m+1, r, pos);
        combine(n);
    }
}

void decrement(int n, int l, int r, int pos){
    if (l > r) return;
    if (l == r){
        int erase = 0;
        for (pii p : t[n]){
            t[n][p.first-1] = 1;
            erase = p.first;
            break;
        }
        t[n].erase(erase);
    }
    else {
        int m = (l+r)/2;
        if (pos <= m) decrement(n*2, l, m, pos);
        else decrement(n*2+1, m+1, r, pos);
        combine(n);
    }
}

ll query(int n, int l, int r, int tl, int tr, int v){
    if (l > r) return 0;
    if (l == tl && r == tr){
        return t[n][v];
    }
    else {
        int m = (tl+tr)/2;
        ll left = query(n*2, l, min(r, m), tl, m, v);
        ll right = query(n*2+1, max(m+1, l), r, m+1, tr, v);
        return left+right;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    build(1, 0, n-1);
    for (int i = 0; i < q; i++){
        int Q;
        cin >> Q;
        if (Q == 1){
            int x;
            cin >> x;
            increment(1, 0, n-1, x-1);
        }
        else if (Q == 2){
            int x;
            cin >> x;
            decrement(1, 0, n-1, x-1);
        }
        else {
            int l, r, x;
            cin >> l >> r >> x;
            cout << query(1, l-1, r-1, 0, n-1, x) << "\n";
        }
    }
}