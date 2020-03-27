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

int a[100010], t[400010];

void build(int node, int l, int r){
    if (l == r) t[node] = a[l];
    else {
        int m = (l + r) / 2;
        build(node * 2, l, m);
        build(node * 2 + 1, m + 1, r);
        t[node] = max(t[node * 2], t[node * 2 + 1]);
    }
}

int query(int node, int l, int r, int tl, int tr){
    if (l > r) return INT_MIN;
    if (l == tl && r == tr) return t[node];
    int m = (tl+tr)/2;
    return max(query(node*2, l, min(r, m), tl, m), query(node*2+1, max(m+1, l), r, m+1, tr));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    build(1, 0, n-1);
    while (m--){
        int l, r;
        cin >> l >> r;
        cout << query(1, l-1, r-1, 0, n-1) << "\n";
    }
}