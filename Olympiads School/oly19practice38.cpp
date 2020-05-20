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

const int MM = 3e5+5, m = 998244353;
int dep[MM], p[MM], L[MM][20];
ll pre[MM][50];
vi adj[MM];
void dfs(int v, int pa, int lvl){
    dep[v] = lvl;
    for (int u : adj[v]){
        if (u != pa){
            p[u] = v;
            dfs(u, v, lvl+1);
        }
    }
}
ll mod_pow(int base, int exp){
    if (exp == 0) return 1;
    ll ans = mod_pow(base, exp/2);
    ans = ans * ans%m;
    if (exp % 2 == 1) return ans*base%m;
    return pre[base][exp] = ans;
}
int lca(int u, int v){
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 19; i >= 0; i--){
        if (dep[u] - pow(2, i) >= dep[v]){
            u = L[u][i];
        }
    }
    if (u == v) return v;
    for (int i = 19; i >= 0; i--){
        if (L[u][i] != L[v][i]){
            u = L[u][i], v = L[v][i];
        }
    }
    return L[u][0];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, 0, 0);
    for (int j = 0; j <= 19; j ++){
        for (int i = 0; i <= n; i++){
            if (j == 0) L[i][j] = p[i];
            else L[i][j] = L[L[i][j-1]][j-1];
        }
    }
    int Q;
    cin >> Q;
    while (Q--){
        int u, v, k;
        cin >> u >> v >> k;
        int LCA = lca(u, v);
        ll ans = 0;
        while (u != LCA){
            if (pre[dep[u]][k] == 0) pre[dep[u]][k] = mod_pow(dep[u], k);
            ans = (pre[dep[u]][k] + ans)%m;
            u = p[u];
        }
        while (v != LCA){
            if (pre[dep[v]][k] == 0) pre[dep[v]][k] = mod_pow(dep[v], k);
            ans = (pre[dep[v]][k] + ans)%m;
            v = p[v];
        }
        if (pre[dep[LCA]][k] == 0) pre[dep[LCA]][k] = mod_pow(dep[LCA], k);
        ans = (pre[dep[LCA]][k] + ans)%m;
        cout << ans%m << "\n";
    }
}