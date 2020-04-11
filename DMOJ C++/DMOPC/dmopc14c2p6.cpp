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

const int MAXN = 1e5+10;
vector<tuple<int, int, int, int>> queries;
ll t[4*MAXN], ans[MAXN];

void update(int node, int tl, int tr, int x, int v){
    if (tl == tr) t[node] = v;
    else {
        int m = (tl+tr)/2;
        if (x <= m) update(node*2, tl, m, x, v);
        else update(node*2+1, m+1, tr, x, v);
        t[node] = t[node*2] + t[node*2+1];
    }
}

ll query(int node, int l, int r, int tl, int tr){
    if (l == tl && r == tr) return t[node];
    if (l > r) return 0;
    int m = (tl+tr)/2;
    return query(node*2, l, min(r, m), tl, m) + query(node*2+1, max(m+1, l), r, m+1, tr);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n;
    vii A;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        A.pb(mp(x, i));
    }
    cin >> q;
    for (int i = 0; i < q; i++){
        int a, b, m;
        cin >> a >> b >> m;
        queries.pb(make_tuple(m, a, b, i));
    }
    sort(A.begin(), A.end());
    sort(queries.begin(), queries.end());
    int prev = -1;
    for (int i = q-1, j = n-1; i >= 0; i--){
        int m = get<0>(queries[i]);
        // Add new trees with height >= m
        if (m != prev){
            while (A[j].first >= m && j >= 0){
                update(1, 0, n-1, A[j].second, A[j].first);
                j--;
            }
        }
        int a = get<1>(queries[i]);
        int b = get<2>(queries[i]);
        ans[get<3>(queries[i])] = query(1, a, b, 0, n-1);
        prev = m;
    }
    for (int i = 0; i < q; i++){
        cout << ans[i] << "\n";
    }
}
