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
int dep[MM], p[MM], L[MM][18];
ll dis[MM], dp[MM][2]; // 0 = node a, 1 = node b
vii adj[MM];
void dfs(int v, int pa, int lvl, int d){
    dep[v] = lvl;
    for (pii u : adj[v]){
        if (u.first != pa){
            p[u.first] = v;
            dis[u.first] = d+u.second;
            dfs(u.first, v, lvl+1, d+u.second);
        }
    }
}
int lca(int u, int v){
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 17; i >= 0; i--){
        if (dep[u] - pow(2, i) >= dep[v]){
            u = L[u][i];
        }
    }
    if (u == v) return u;
    for (int i = 17; i >= 0; i--){
        if (L[u][i] != L[v][i]){
            u = L[u][i], v = L[v][i];
        }
    }
    return L[u][0];
}
ll dist(int u, int v){
    int LCA = lca(u, v);
    return dis[u] + dis[v] - 2*dis[LCA];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, d;
    cin >> n >> d;
    for (int i = 1; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb({b, c});
        adj[b].pb({a, c});
    }
    dfs(1, 0, 1, 0);
    for (int j = 0; j <= 17; j++){
        for (int i = 1; i <= n; i++){
            if (j == 0) L[i][j] = p[i];
            else L[i][j] = L[L[i][j-1]][j-1];
        }
    }
    int prevA = 1, prevB = 1;
    for (int i = 1; i <= d; i++){
        int a, b;
        cin >> a >> b;
        dp[i][0] = min(dp[i-1][0] + dist(prevA, b), dp[i-1][1] + dist(prevB, b)) + dist(b, a);
        dp[i][1] = min(dp[i-1][0] + dist(prevA, a), dp[i-1][1] + dist(prevB, a)) + dist(b, a);
        prevA = a, prevB = b;
    }
    cout << min(dp[d][0], dp[d][1]) << "\n";
}