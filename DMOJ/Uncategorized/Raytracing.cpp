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

int arr[10000], tree[40000][10000];

void build(int n, int l, int r){
    if (l > r) return;
    else if (l == r){
        tree[n][arr[l]] = 1;
    }
    else {
        int m = (l+r)/2;
        build(n*2, l, m);
        build(n*2+1, m+1, r);
        for (int i = 0; i < 8200; i++){
            tree[n][i] = tree[n*2][i] + tree[n*2+1][i];
        }
    }
}

void update(int n, int v, int pos, int l, int r){
    if (l > r) return;
    else if (l == r){
        tree[n][arr[pos]]--;
        arr[pos] = v;
        tree[n][v]++;
    }
    else {
        int m = (l+r)/2;
        if (pos <= m){
            update(n*2, v, pos, l, m);
        }
        else {
            update(n*2+1, v, pos, m+1, r);
        }
        for (int i = 0; i < 8200; i++){
            tree[n][i] = tree[n*2][i] + tree[n*2+1][i];
        }
    }
}

int query(int n, int l, int r, int tl, int tr, int a, int b){
    if (tl > r || tr < l || l > r) return 0;
    else if (l <= tl && tr <= r){
        int sum = 0;
        for (int i = a; i <= b; i++){
            sum += tree[n][i];
        }
        return sum;
    }
    else {
        int m = (tl+tr)/2;
        int left = query(n*2, l, min(r, m), tl, m, a, b);
        int right = query(n*2+1, max(l, m+1), r, m+1, tr, a, b);
        return left+right;
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    build(1, 0, n-1);
    cin >> q;
    while (q--){
        int c;
        cin >> c;
        if (c == 1){
            int i, j, a, b;
            cin >> i >> j >> a >> b;
            cout << query(1, i, j, 0, n-1, a, b) << endl;
        }
        else {
            int i, h;
            cin >> i >> h;
            update(1, h, i, 0, n-1);
        }
    }
}