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

ll tree[800010], lazy[800010], a[200010], m;

void build(int node, int l, int r){
    if (l > r) return;
    if (l == r){
        tree[node] = a[l]%m;
    }
    else {
        int mid = (l+r)/2;
        build(node*2, l, mid);
        build(node*2+1, mid+1, r);
        tree[node] = (tree[node*2]%m + tree[node*2+1]%m)%m;
    }
}

void update(int node, int tl, int tr, int l, int r, int val){
    if (lazy[node] != 0){
        tree[node] = (tree[node]%m + (abs(tr-tl+1)%m*lazy[node]%m)%m)%m;
        if (tl != tr){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (tl > r || tr < l || l > r) return;
    if (tl == l && tr == r){
        tree[node] = (tree[node]%m + (abs(tr-tl+1)%m*val%m)%m)%m;
        if (tl != tr){
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
    }
    else {
        int mid = (tl+tr)/2;
        update(node*2, tl, mid, l, min(mid, r), val);
        update(node*2+1, mid+1, tr, max(l, mid+1), r, val);
        tree[node] = (tree[node*2]%m + tree[node*2+1]%m)%m;
    }
}

ll query(int node, int tl, int tr, int l, int r){
    if (lazy[node] != 0){
        tree[node] = (tree[node]%m + (abs(tr-tl+1)%m*lazy[node]%m)%m)%m;
        if (tl != tr){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (tl > r || tr < l || l > r){
        return 0;
    }
    if (tl == l && tr == r){
        return tree[node]%m;
    }
    else {
        int mid = (tl+tr)/2;
        ll left = query(node*2, tl, mid, l, min(r, mid));
        ll right = query(node*2+1, mid+1, tr, max(mid+1, l), r);
        return (left%m+right%m)%m;
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> m >> n >> q;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    build(1, 0, n-1);
    while (q--){
        int c;
        cin >> c;
        if (c == 1){
            int l, r, x;
            cin >> l >> r >> x;
            update(1, 0, n-1, l-1, r-1, x);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << query(1, 0, n-1, l-1, r-1) << endl;
        }
    }
}
