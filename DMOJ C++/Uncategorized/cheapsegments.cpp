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

struct seg{
    int l, r, v, id;
};

bool cmp(seg a, seg b){
    return a.l < b.l;
}

bool check(seg a, seg b){
    return b.l < a.r;
}
const int MM = 1e5+5, LOG = 18;
vi adj[MM];
int dep[MM], pa[MM], anc[MM][LOG];

void dfs(int v, int p, int lvl){
    dep[v] = lvl;
    for (int u : adj[v]){
        if (u != p){
            pa[u] = v;
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
    if (u == v) return v;
    for (int i = LOG-1; i >= 0; i--){
        if (anc[u][i] != anc[v][i]){
            u = anc[u][i], v = anc[v][i];
        }
    }
    return anc[u][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<seg> vec;
    for (int i = 1; i <= n; i++){
        int l, r, v;
        cin >> l >> r >> v;
        vec.pb({l, r, v, i});
    }
    vec.pb({0, inf, inf, 0});
    sort(all(vec), cmp);
    stack<int> s;
    for (int i = 0; i <= n; i++){
        if (s.empty()){
            s.push(i);
            continue;
        }
        int ind = s.top();
        if (check(vec[ind], vec[i])){
            adj[vec[i].id].pb(vec[ind].id);
            adj[vec[ind].id].pb(vec[i].id);
            if (vec[i].v < vec[ind].v || (vec[i].v == vec[ind].v && vec[i].id < vec[ind].id)){
                s.push(i);
            }
        }
        else{
            s.pop();
            i--;
        }
    }
    dfs(0, -1, 1);
    for (int j = 0; j < LOG; j++){
        for (int i = 1; i <= n; i++){
            if (j == 0) anc[i][j] = pa[i];
            else anc[i][j] = anc[anc[i][j-1]][j-1];
        }
    }
    int Q;
    cin >> Q;
    while (Q--){
        int a, b;
        cin >> a >> b;
        int LCA = lca(a, b);
        if (LCA == a || LCA == b || LCA == 0){
            LCA = pa[LCA];
            if (LCA == 0) cout << "-1\n";
            else cout << LCA << "\n";
        }
        else cout << LCA << '\n';
    }
}