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
#define inf 0x3f3f3f3f

const int MM = 5e5+5;
vi adj[MM];
int down[MM], up[MM];

void dfs(int v, int pa){
    down[v] = 1;
    up[v] = up[pa]+1;
    for (int w : adj[pa]){
        if (w != v) up[v] = max(up[v], up[w]+2);
    }
    for (int u : adj[v]){
        if (u != pa){
            dfs(u, v);
            down[v] = max(down[u]+1, down[v]);
        }
    }
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
    dfs(1, 0);
    for (int i = 1; i <= n; i++){
        cout << max(down[i], up[i]) << '\n';
    }
}