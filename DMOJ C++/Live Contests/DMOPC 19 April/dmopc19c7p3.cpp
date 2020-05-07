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
const int MM = 1e6+5;
ll w[MM], szw[MM];
int sz[MM], inv[MM];
vi adj[MM];

void dfs(int v, int p){
    szw[v] = w[v];
    sz[v] = 1;
    for (int u : adj[v]){
        if (u != p){
            dfs(u, v);
            szw[v] += szw[u];
            sz[v] += sz[u];
        }
    }
}

void dfs2(int v, int p){
    inv[v] = 1;
    for (int u : adj[v]){
        if (u != p && sz[u] < sz[v]) dfs2(u, v);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    ll tot = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> w[i];
        tot += w[i];
    }
    for (int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++){
        if (tot - szw[i] >= k && tot - szw[i] <= k*2){
            cout << n-sz[i] << '\n';
            dfs2(i, 0);
            for (int j = 1; j <= n; j++){
                if (inv[j] == 0) cout << j << ' ';
            }
            return 0;
        }
    }
}