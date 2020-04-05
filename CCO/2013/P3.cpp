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

int N, dis[400010], dia;
ll cnt[400010], num;
vi adj[400010];
void dfs(int u, int pa){
    dis[u] = 0; cnt[u] = 1;
    for (int v : adj[u]){
        if (v == pa) continue;
        dfs(v, u);
        if (dis[u] + dis[v] + 1 > dia){
            dia = dis[u] + dis[v] + 1;
            num = cnt[u]*cnt[v];
        }
        else if (dis[u] + dis[v] + 1 == dia){
            num += cnt[u]*cnt[v];
        }
        if (dis[v] + 1 > dis[u]){
            dis[u] = dis[v] + 1;
            cnt[u] = cnt[v];
        }
        else if (dis[v] + 1 == dis[u]){
            cnt[u] += cnt[v];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i < N; i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, 0);
    cout << dia+1 << " " << num;
}