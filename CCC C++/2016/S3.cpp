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
int d[MM], pa[MM], sz[MM], cnt;
bool mark[MM], pho[MM];


void dfs(int v, int p, int dis){
    pa[v] = p;
    d[v] = dis;
    for (int u : adj[v]){
        if (u != p && mark[u]){
            dfs(u, v, dis+1);
        }
        else if (!mark[u]) cnt += sz[u];
    }
}

int getsz(int v, int p){
    sz[v] = 1;
    for (int u : adj[v]){
        if (u != p){
            sz[v] += getsz(u, v);
        }
    }
    return sz[v];
}

void prune(int v, int p){
    bool flag = pho[v];
    for (int u : adj[v]){
        if (u != p && !mark[u]){
            prune(u, v);
            flag |= mark[u];
        }
    }
    mark[v] = flag;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, rt;
    cin >> N >> M;
    for (int i = 0; i < M; i++){
        int x;
        cin >> x;
        rt = x;
        pho[x] = true;
    }
    for (int i = 1; i < N; i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    prune(rt, -1);
    dfs(rt, -1, 0);
    getsz(rt, -1);
    int mx = 0;
    for (int i = 0; i < N; i++){
        if (d[i] > d[mx]) mx = i;
    }
    dfs(mx, -1, 0);
    mx = 0;
    for (int i = 0; i < N; i++){
        mx = max(mx, d[i]);
    }
    cout << (N-cnt-1)*2 - mx << "\n";
}