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

const int MM = 2*1e5+5;
int lv[MM], sz[MM];
vi adj[MM];

void dfs(int u, int p){
    lv[u] = lv[p]+1;
    for (int v : adj[u]){
        if (v != p) dfs(v, u);
    }
}

void getsz(int u, int p){
    sz[u] = 1;
    for (int v : adj[u]){
        if (v != p){
            getsz(v, u);
            sz[u] += sz[v];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k, cnt = 0;
    vi ans;
    cin >> n >> k;
    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, 0);
    getsz(1, 0);
    for (int i = 1; i <= n; i++){
        ans.pb(sz[i]-lv[i]);
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < n-k; i++){
        cnt += ans[n-1-i];
    }
    cout << cnt;
}