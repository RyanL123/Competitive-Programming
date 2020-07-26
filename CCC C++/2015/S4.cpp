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

const int MM = 2e3+5;
int K, N, M, A, B, sp[MM][205], vis[MM];
vector<pair<int, pii>> adj[MM];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> K >> N >> M;
    for (int i = 0, a, b, t, h; i < M; i++) {
        cin >> a >> b >> t >> h;
        adj[a].pb({t, {b, h}});
        adj[b].pb({t, {a, h}});
    }
    cin >> A >> B;
    memset(sp, 0x3f, sizeof(sp));
    for (int i = 0; i <= 200; i++) sp[A][i] = 0;
    priority_queue<pair<int, pii>> pq;
    pq.push({0, {A, 0}});
    while (!pq.empty()) {
        int t = -pq.top().first;
        int v = pq.top().second.first;
        int h = pq.top().second.second;
        pq.pop();
        if (t > sp[v][h]) continue;
        for (pair<int, pii> p : adj[v]) {
            int ut = p.first, u = p.second.first, uh = p.second.second;
            if (sp[u][h+uh] > t+ut) {
                if (h + uh >= K) continue;
                sp[u][uh+h] = sp[v][h] + ut;
                pq.push({-t-ut, {u, h+uh}});
            }
        }
    }
    int ans = inf;
    for (int i = 0; i <= 200; i++) ans = min(ans, sp[B][i]);
    cout << (ans==inf?-1:ans) << '\n';
}