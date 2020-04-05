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

vector<pair<int, pii>> adj[1010];
int n, m;
int find(int minFlow){
    pii sp[1010];
    int visited[1010];
    for (int i = 0; i <= 1000; i++){
        sp[i].first = inf;
        sp[i].second = inf;
        visited[i] = false;
    }
    priority_queue<pair<int, pii>> pq;
    visited[1] = true;
    sp[1].first = 0;
    pq.push({0, {1, 1000}});
    while (!pq.empty()){
        int cost = -pq.top().first;
        int node = pq.top().second.first;
        int flow = pq.top().second.second;
        pq.pop();
        for (pair<int, pii> v : adj[node]){
            if (!visited[v.second.first] && v.second.second >= minFlow){
                if (sp[v.second.first].first > cost + v.first){
                    sp[v.second.first].first = cost + v.first;
                    sp[v.second.first].second = min(v.second.second, flow);
                    pq.push({-(cost + v.first), {v.second.first, min(v.second.second, flow)}});
                }
            }
        }
    }
    if (sp[n].first == inf) return 0;
    return sp[n].second*1000000 / sp[n].first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b, c, f;
        cin >> a >> b >> c >> f;
        adj[a].push_back({c, {b, f}});
        adj[b].push_back({c, {a, f}});
    }
    for (int i = 0; i <= 1000; i++){
        ans = max(ans, find(i));
    }
    cout << ans;
}