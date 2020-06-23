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

const int MM = 1e5+5;
vi adj[MM];
int cat[MM], mx[MM], ans, n, m;

void dfs(int v, int p){
    if (cat[p] && cat[v]) cat[v] += cat[p];
    mx[v] = max(mx[p], cat[v]);
    if (adj[v].size() == 1 && adj[v][0] == p){
        ans += (mx[v] <= m);
        return;
    }
    for (int u : adj[v]){
        if (u != p){
            dfs(u, v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> cat[i];
    }
    for (int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1, 0);
    cout << ans << '\n';
}