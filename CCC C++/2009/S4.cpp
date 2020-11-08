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

const int MM = 5e3+5;
int N, K, T, D, dis[MM], vis[MM];
vii adj[MM], P;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> T;
    for (int i = 0, x, y, c; i < T; i++) {
        cin >> x >> y >> c;
        adj[x].eb(y, c);
        adj[y].eb(x, c);
    }
    cin >> K;
    for (int i = 0, z, p; i < K; i++) {
        cin >> z >> p;
        P.eb(z, p);
    }
    cin >> D;
    priority_queue<pii> pq;
    pq.push({0, D});
    memset(dis, 0x3f, sizeof(dis));
    dis[D] = 0;
    vis[D] = true;
    while (!pq.empty()) {
        int c = -pq.top().first, v = pq.top().second;
        vis[v] = true; 
        pq.pop();
        if (dis[v] < c) continue;
        for (pii p : adj[v]) {
            if (!vis[p.first] && dis[p.first] > c + p.second) {
                dis[p.first] = c + p.second;
                pq.push({-(c + p.second), p.first});
            }
        }
    }
    int ans = inf;
    for (int i = 0; i < K; i++) ans = min(ans, dis[P[i].first]+P[i].second);
    cout << ans << '\n';
}