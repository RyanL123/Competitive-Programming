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

struct edge{
    int a, b, d, t;
};

vector<edge> e;
int n, m, q;

bool solve(int x, int y){
    vi adj[n+1];
    bool visited[n+1];
    memset(visited, false, sizeof(visited));
    int start = -1;
    for (edge E : e){
        if (E.d >= x && E.t <= y){
            adj[E.a].pb(E.b);
            adj[E.b].pb(E.a);
            if (start == -1) start = E.a;
        }
    }
    if (start == -1) return false;
    visited[start] = true;
    queue<int> Q;
    Q.push(start);
    while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        for (int u : adj[v]){
            if (!visited[u]){
                visited[u] = true;
                Q.push(u);
            }
        }
    }
    for (int i = 1; i <= n; i++){
        if (!visited[i]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++){
        int a, b, d, t;
        cin >> a >> b >> d >> t;
        e.pb({a, b, d, t});
    }
    for (int i = 0; i < q; i++){
        int x, y;
        cin >> x >> y;
        if (solve(x, y)) cout << "YES\n";
        else cout << "NO\n";
    }
}