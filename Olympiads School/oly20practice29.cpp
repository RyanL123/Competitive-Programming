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

vii g[310];

int bfs(int a, int b){
    int atk[310];
    for (int i = 0; i < 310; i++) atk[i] = inf;
    atk[a] = 0;
    queue<pii> q;
    q.push(mp(a, 0));
    while (!q.empty()){
        int node = q.front().first;
        int cost= q.front().second;
        q.pop();
        for (pii n : g[node]){
            if (atk[n.first] > max(cost, n.second)){
                atk[n.first] = max(cost, n.second);
                n.second = min(atk[n.first], max(cost, n.second));
                q.push(mp(n.first, min(atk[n.first], max(cost, n.second))));
            }
        }
    }
    if (atk[b] != inf) return atk[b];
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, t;
    cin >> n >> m >> t;
    for (int i = 0; i < m; i++){
        int s, e, h;
        cin >> s >> e >> h;
        g[s].pb(mp(e, h));
    }
    for (int i = 0; i < t; i++){
        int a, b;
        cin >> a >> b;
        cout << bfs(a, b) <<"\n";
    }
}
