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

struct node{
    int pa = 0;
    pii mx;
};
const int MM = 1e5+5;
int dep[MM], p[MM], dis[MM];
vii adj[MM];
node anc[MM][18];

pii cmp(pii a, pii b){
    if (a.first < b.first){
        return {b.first, max(a.first, b.second)};
    }
    else {
        return {a.first, max(b.first, a.second)};
    }
}

void dfs(int v, int pa, int lvl){
    dep[v] = lvl;
    for (pii u : adj[v]){
        if (u.first != pa){
            p[u.first] = v;
            dis[u.first] = u.second;
            dfs(u.first, v, lvl+1);
        }
    }
}

int lca(int u, int v){
    if (p[u] == v || p[v] == u) return -1;
    pii mx = {0, 0};
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 17; i >= 0; i--){
        if (dep[u] - (1 << i) >= dep[v]){
            mx = cmp(anc[u][i].mx, mx);
            u = anc[u][i].pa;
        }
    }
    if (u == v) return mx.second;
    for (int i = 17; i >= 0; i--){
        if (anc[u][i].pa != anc[v][i].pa){
            mx = cmp(anc[u][i].mx, mx);
            mx = cmp(anc[v][i].mx, mx);
            u = anc[u][i].pa, v = anc[v][i].pa;
        }
    }
    mx = cmp(anc[u][0].mx, mx);
    mx = cmp(anc[v][0].mx, mx);
    return mx.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].pb({b, w});
        adj[b].pb({a, w});
    }
    dfs(1, 0, 1);
    for (int j = 0; j <= 17; j++){
        for (int i = 1; i <= n; i++){
            if (j == 0){
                anc[i][j].pa = p[i];
                anc[i][j].mx.first = dis[i];
                anc[i][j].mx.second = 0;
            }
            else {
                anc[i][j].pa = anc[anc[i][j-1].pa][j-1].pa;
                pii n1 = anc[i][j-1].mx, n2 = anc[anc[i][j-1].pa][j-1].mx;
                anc[i][j].mx = cmp(n1, n2);
            }
        }
    }
    int Q;
    cin >> Q;
    while (Q--){
        int s, t;
        cin >> s >> t;
        cout << lca(s, t) << '\n';
    }
}