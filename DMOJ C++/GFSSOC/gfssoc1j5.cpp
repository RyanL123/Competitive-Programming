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

vi adj[1005];
int ans[1005][1005];

int n, m, t;

void bfs(int a){
    int steps[1005];
    for (int i = 0; i <= 1000; i++) steps[i] = inf;
    queue<int> q;
    steps[a] = 0;
    q.push(a);
    while (!q.empty()){
        int v = q.front();
        q.pop();
        for (int u : adj[v]){
            if (steps[u] > steps[v]+t){
                steps[u] = steps[v]+t;
                q.push(u);
            }
        }
    }
    for (int i = 1; i <= n; i++){
        ans[a][i] = steps[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> t;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }
    for (int i = 1; i <= n; i++){
        bfs(i);
    }
    int q;
    cin >> q;
    while (q--){
        int a, b;
        cin >> a >> b;
        if (ans[a][b] == inf) cout << "Not enough hallways!\n";
        else cout << ans[a][b] << '\n';
    }
}
