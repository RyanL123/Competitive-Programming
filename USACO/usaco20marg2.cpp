#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define srt(x) sort(x.begin(), x.end())
#define inf 0x3f3f3f3f

int p[200005], val[200005];
vi adj[200005];

int find(int v){
    if (p[v] == v) return v;
    return find(p[v]);
}

void dfs(int u){
    if (adj[u].size() <= 1) return;
    int rt = find(adj[u][0]);
    while (adj[u].size() > 1){
        int rv = find(adj[u].back());
        adj[u].pop_back();
        if (rt == rv) continue;
        if (adj[rt].size() < adj[rv].size()) swap(adj[rt], adj[rv]);
        p[rv] = rt;
        adj[rt].insert(adj[rt].end(), adj[rv].begin(), adj[rv].end());
    }
    dfs(rt);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, cnt = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }
    for (int i = 1; i <= n; i++) dfs(i);
    for (int i = 1; i <= n; i++){
        int rt = find(i);
        if (val[rt] == 0) val[rt] = ++cnt;
        cout << val[rt] << "\n";
    }
}