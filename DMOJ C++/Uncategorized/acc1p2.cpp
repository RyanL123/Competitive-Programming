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

int p[100010], rk[100010];
vi adj[100010];

int find(int v){
    if (p[v] == v) return v;
    return p[v] = find(p[v]);
}

void join(int bv, int ev){
    int pb = find(bv);
    int pe = find(ev);
    if (rk[pb] == rk[pe]){
        rk[pb]++;
        p[pe] = pb;
    }
    else if (rk[pb] > rk[pe]){
        rk[pb] += rk[pe];
        p[pe] = pb;
    }
    else {
        rk[pe] += rk[pb];
        p[pb] = pe;
    }
}

int bfs(int a, int b){
    int steps1[100010];
    int steps2[100010];
    for (int i = 1; i <= 100000; i++) {
        steps1[i] = inf;
        steps2[i] = inf;
    }
    steps1[a] = 0;
    steps2[b] = 0;
    queue<int> q1;
    queue<int> q2;
    q1.push(a);
    q2.push(b);
    while (!q1.empty() && !q2.empty()){
        int v1 = q1.front();
        int v2 = q2.front();
        q1.pop();
        q2.pop();
        for (int u : adj[v1]){
            if (steps1[u] > steps1[v1]+1){
                steps1[u] = steps1[v1]+1;
                if (steps2[u] != inf) return steps1[u] + steps2[u];
                else q1.push(u);
            }
        }
        for (int u : adj[v2]){
            if (steps2[u] > steps2[v2]+1){
                steps2[u] = steps2[v2]+1;
                if (steps1[u] != inf) return steps1[u] + steps2[u];
                else q2.push(u);
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++){
        p[i] = i;
        rk[i] = 1;
    }
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
        join(a, b);
    }
    for (int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        if (a == b) cout << "0\n";
        else if (find(a) != find(b)) cout << "-1\n";
        else cout << bfs(a, b) << "\n";
    }
}