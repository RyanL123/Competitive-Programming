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

int n, sz[100010], val[2][200010], path[200010];
vii adj[100010];
bool done[100010];
ll ans;

void getsz(int u, int pa){
    sz[u] = 1;
    for (pii e : adj[u]){
        if (e.first != pa && !done[e.first]){
            getsz(e.first, u);
            sz[u] += sz[e.first];
        }
    }
}

int getcent(int u, int pa, int tot){
    for (pii e : adj[u]){
        if (e.first != pa && !done[e.first] && sz[e.first]*2 > tot){
            return getcent(e.first, u, tot);
        }
    }
    return u;
}

void dfs1(int u, int sum, int pa){
    path[sum+n]++;
    ans += val[1][-sum+n] + (path[sum+n] > 1)*val[0][-sum+n];
    for (pii e : adj[u]){
        if (e.first != pa && !done[e.first]) dfs1(e.first, sum+e.second, u);
    }
    path[sum+n]--;
}

void dfs2(int u, int sum, int pa){
    path[sum+n]++;
    if (path[sum+n] > 1) val[1][sum+n]++;
    else val[0][sum+n]++;
    for (pii e : adj[u]){
        if (e.first != pa && !done[e.first]){
            dfs2(e.first, sum+e.second, u);
        }
    }
    path[sum+n]--;
}

void solve(int rt){
    getsz(rt, 0);
    rt = getcent(rt, 0, sz[rt]);
    done[rt] = true;
    for (int i = -sz[rt]+n; i <= sz[rt]+n; i++){
        path[i] = val[0][i] = val[1][i] = 0;
    }
    val[0][n] = 1; // root has no stop city with path sum = 0
    for (pii e : adj[rt]){
        int v = e.first, w = e.second;
        if (!done[v]){
            path[n] = 0;
            dfs1(v, w, rt);
            path[n] = 1;
            dfs2(v, w, rt);
        }
    }
    for (pii e : adj[rt]){
        if (!done[e.first]) solve(e.first);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i < n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        w = (w == 1 ? 1 : -1);
        adj[u].pb(mp(v, w));
        adj[v].pb(mp(u, w));
    }
    solve(1);
    cout << ans << endl;
}