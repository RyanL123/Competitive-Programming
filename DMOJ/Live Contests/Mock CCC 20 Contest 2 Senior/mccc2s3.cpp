#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

vector<pair<int, int>> g[60000];
bool notVisited[60000];
int sp[60000];
int dijkstras(int start, int end){
    for (int i = 0; i < 60000; i++){
        notVisited[i] = true;
        sp[i] = INT_MAX;
    }
    priority_queue<pair<int, int>> pq;
    sp[start] = 0;
    notVisited[start] = false;
    pq.push(make_pair(0, start));
    while (!pq.empty()){
        int cost = -pq.top().first;
        int node = pq.top().second;
        pq.pop();
        notVisited[node] = false;
        if (cost > sp[node]) continue;
        for (int i = 0; i < g[node].size(); i++){
            int connectedNode = g[node][i].second;
            int connectedCost = g[node][i].first;
            if (notVisited[connectedNode]){
                if ((connectedCost | cost) < sp[connectedNode]){
                    sp[connectedNode] = connectedCost | cost;
                    pq.push(make_pair(-(connectedCost | cost), connectedNode));
                }
            }
        }
    }
    return sp[end];
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++){
        int u, v, k;
        cin >> u >> v >> k;
        if (find(g[u].begin(), g[u].end(), make_pair(k, v)) == g[u].end()){
            g[u].emplace_back(k, v);
            g[v].emplace_back(k, u);
        }
    }
    for (int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        cout << dijkstras(a, b) << endl;
    }
}