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

int n, m, c, ind[100010], val[100010];
vii adj[100010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> c;
    for (int i = 1, x; i <= n; i++){
        cin >> x;
        adj[0].push_back(mp(i, x));
        ind[i]++;
    }
    for (int i = 1; i <= c; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb(mp(v, w));
        ind[v]++;
    }
    queue<int> q;
    q.push(0);
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (pii e : adj[u]){
            int v = e.first, w = e.second;
            val[v] = max(val[v], val[u]+w);
            if (--ind[v] == 0) q.push(v);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << val[i] << endl;
    }
}