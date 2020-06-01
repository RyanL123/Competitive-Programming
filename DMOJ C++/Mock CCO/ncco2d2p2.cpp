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

const int MM = 1e5+5, LOG = 18;
map<pii, int> m;
vi adj[MM], clr[MM];
int dep[MM], anc[MM][LOG], diff[MM];

void join(int u, int v, int id){
    if (u > v) swap(u, v);
    pii p = {u, v};
    if (m[p] == 0) m[p] = id;
    else {
        adj[m[p]].pb(id);
        adj[id].pb(m[p]);
    }
}

void dfs(int v, int p, int lvl){
    dep[v] = lvl;
    anc[v][0] = p;
    for (int u : adj[v]){
        if (u != p){
            dfs(u, v, lvl+1);
        }
    }
}

int lca(int u, int v){
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = LOG-1; i >= 0; i--){
        if (dep[u] - (1 << i) >= dep[v]){
            u = anc[u][i];
        }
    }
    if (u == v) return u;
    for (int i = LOG-1; i >= 0; i--){
        if (anc[u][i] != anc[v][i]){
            u = anc[u][i], v = anc[v][i];
        }
    }
    return anc[u][0];
}

void dfs2(int v, int p){
    for (int u : adj[v]){
        if (u != p){
            dfs2(u, v);
            diff[v] += diff[u];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b, c, d;
    cin >> n;
    for (int i = 1; i <= n-2; i++){
        cin >> a >> b >> c >> d;
        join(a, b, i);
        join(c, b, i);
        join(a, c, i);
        clr[d].pb(i);
    }
    dfs(1, -1, 1);
    for (int j = 1; j < LOG; j++){
        for (int i = 1; i <= n; i++){
            anc[i][j] = anc[anc[i][j-1]][j-1];
        }
    }
    for (int i = 1; i <= n; i++){
        if (!clr[i].empty()){
            for (int j = 0; j < clr[i].size()-1; j++){
                int u = clr[i][j], v = clr[i][j+1], w = lca(u, v);
                diff[u]++, diff[v]++, diff[w]-=2;
            }
        }
    }
    dfs2(1, -1);
    int ans = 0;
    for (int i = 2; i <= n-2; i++){
        if (diff[i] == 0) ans++;
    }
    cout << ans << '\n';
}