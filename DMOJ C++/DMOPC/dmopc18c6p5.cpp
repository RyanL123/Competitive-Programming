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

struct event{
    bool goose;
    int x, lo, hi, v;
};
const ll MM = 1e9+5;
int tree[4*MM], lzy[4*MM], n, m, k, q, t;
map<pii, int> M;
vector<event> ex;
vector<event> ey;
void push(int node, int l, int r, int tl, int tr){
    if (tl == tr || l == r) return;
    lzy[node*2] += lzy[node];
    lzy[node*2+1] += lzy[node];
    lzy[node] = 0;
}
int rmq(int node, int l, int r, int tl, int tr){
    if (l > r) return -1;
    push(node, l, r, tl, tr);
    if (l == tl && r == tr) return tree[node];
    int mid = (tl+tr)/2;
    return max(rmq(node*2, l, min(r, mid), tl, mid), rmq(node*2+1, max(l, mid+1), r, mid+1, tr));
}
void decr(int node, int l, int r, int tl, int tr){
    if (l > r) return;
    push(node, l, r, tl, tr);
    if (l == tl && r == tr) lzy[node]--;
    else {
        int mid = (tl+tr)/2;
        decr(node*2, l, min(r, mid), tl, mid);
        decr(node*2+1, max(l, mid+1), r, mid+1, tr);
        tree[node] = max(tree[node*2], tree[node*2+1]);
    }
}
void incr(int node, int l, int r, int tl, int tr){
    if (l > r) return;
    push(node, l, r, tl, tr);
    if (l == tl && r == tr) lzy[node]++;
    else {
        int mid = (tl+tr)/2;
        decr(node*2, l, min(r, mid), tl, mid);
        decr(node*2+1, max(l, mid+1), r, mid+1, tr);
        tree[node] = max(tree[node*2], tree[node*2+1]);
    }
}
void f(){
    for (event E : ex){
        if (E.goose){
            M[{E.lo, E.hi}] = max(M[{E.lo, E.hi}], rmq(1, E.lo-t, E.hi+t, 0, n));
        }
        else if (E.v < 0){
            decr(1, E.lo, E.hi, 0, n);
        }
        else{
            incr(1, E.lo, E.hi, 0, n);
        }
    }
}
bool cmp(event a, event b){
    return a.x < b.x || (a.x == b.x && a.v < b.v);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k >> q >> t;
    for (int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        ex.pb({true, 0, a, b});
        ey.pb({true, 0, a, b});
    }
    for (int i = 0; i < q; i++){
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        ex.pb({false, c1, r1, r2, 1});
        ex.pb({false, c2, r1, r2, -1});
        ey.pb({false, r2, c1, c2, 1});
        ey.pb({false, r1, c1, c2, -1});
    }
    sort(ex.begin(), ex.end(), cmp);
    f();
    swap(ex, ey);
    sort(ex.begin(), ex.end(), cmp);
    f();
    int ans = 0;
    for (pair<pii, int> p : M){
        ans += p.second;
    }
    cout << ans << '\n';
}