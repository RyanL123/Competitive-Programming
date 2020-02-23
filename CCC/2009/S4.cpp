#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define inf INT_MAX

vii graph[5010];
vii pencil;
int sp[5010];
bool visited[5010];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, t, d, k;
    cin >> n >> t;
    for (int i = 0; i < t; i++){
        int x, y, c;
        cin >> x >> y >> c;
        graph[x].pb(mp(c, y));
        graph[y].pb(mp(c, x));
    }
    cin >> k;
    for (int i = 0; i < k; i++){
        int p, z;
        cin >> z >> p;
        pencil.pb(mp(p, z));
    }
    for (int i = 1; i <= n; i++){
        sp[i] = inf;
    }
    cin >> d;
    priority_queue<pair<int, int>> pq;
    visited[d] = true;
    pq.push(mp(0, d));
    sp[d] = 0;
    while (!pq.empty()){
        int node = pq.top().second;
        int cost = -pq.top().first;
        visited[node] = true;
        pq.pop();
        if (cost > sp[node]) continue;
        for (int i = 0; i < graph[node].size(); i++){
            int connected = graph[node][i].second;
            int connectedCost = graph[node][i].first;
            if (cost + connectedCost < sp[connected] && !visited[connected]){
                pq.push(mp(-(cost+connectedCost), connected));
                sp[connected] = cost+connectedCost;
            }
        }
    }
    int lowest = inf;
    for (int i = 0; i < pencil.size(); i++){
        int node = pencil[i].second;
        int cost = pencil[i].first;
        if (sp[node] + cost < lowest){
            lowest = sp[node] + cost;
        }
    }
    cout << lowest << endl;
}