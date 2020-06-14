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

const int MM = 2e5+5;
int n, val[MM], sz[MM];
ll dp[MM], pa[MM], len[MM];
vi adj[MM];

void dfs1(int u, int p){
    sz[u] = 1; dp[u] = 0;
    for (int v : adj[u]){
        if (v == p) continue;
        dfs1(v, u);
        sz[u] += sz[v];
        dp[u] += dp[v] + sz[v];
    }
}

void dfs2(int u, int p){
    len[u] = dp[u]*(n-sz[u]+1) + pa[u]*sz[u];
    for (int v : adj[u]){
        if (v == p) continue;
        len[u] += (sz[u] - sz[v] - 1) * (dp[v] + sz[v]);
        pa[v] = dp[u] - dp[v] - sz[v] + pa[u] + n - sz[v];
        dfs2(v, u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> val[i];
    }
    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    ll ans = 0;
    for (int i = 1; i <= n; i++){
        ans += val[i]*len[i];
    }
    cout << ans << "\n";
}