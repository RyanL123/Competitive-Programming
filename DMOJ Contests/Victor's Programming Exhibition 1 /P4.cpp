#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <utility>
#include <queue>

using namespace std;

int dijkstras(int start, int end, vector<pair<int, int>>graph[]){
    bool notVisited[100010];
    int sp[100010];
    for (int i = 0; i < 100010; i++){
        notVisited[i] = true;
        sp[i] = INT_MAX;
    }
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    notVisited[start] = false;
    sp[start] = 0;
    while (!pq.empty()){
        int node = pq.top().second;
        int cost = -pq.top().first;
        notVisited[node] = false;
        pq.pop();
        if (cost > sp[node]) continue;
        for (int i = 0; i < graph[node].size(); i++){
            int connectedNode = graph[node][i].second;
            int connectedCost = graph[node][i].first;
            if (notVisited[connectedNode]){
                if (connectedCost + cost < sp[connectedNode]){
                    sp[connectedNode] = connectedCost + cost;
                    pq.push(make_pair(-(connectedCost+cost), connectedNode));
                }
            }
        }
    }
    return sp[end];
}

int main() {
    int n, d;
    cin >> n >> d;
    vector<pair<int, int>> graph[n+1];
    for (int i = 0; i < n-1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(make_pair(c, b));
        graph[b].emplace_back(make_pair(c, a));
    }
    pair<int, int> bananas[d];
    for (int i = 0; i < d; i++){
        int a, b;
        cin >> a >> b;
        bananas[i] = make_pair(a, b);
    }
    vector<pair<int, int>> previousCases = {make_pair(1, 0)};
    // O(2^n) calculates all cases
    for (int i = 0; i < d; i++){
        vector<pair<int, int>> newCases;
        int a = bananas[i].first;
        int b = bananas[i].second;
        if (a == b){
            for (int j = 0; j < previousCases.size(); j++){
                int previousDay = previousCases[j].first;
                int previousCost = previousCases[j].second;
                int dis = dijkstras(previousDay, a, graph) + previousCost;
                newCases.emplace_back(make_pair(a, dis));
            }
        }
        else {
            for (int j = 0; j < previousCases.size(); j++){
                int previousDay = previousCases[j].first;
                int previousCost = previousCases[j].second;
                int disA = dijkstras(previousDay, a, graph) + dijkstras(a, b, graph) + previousCost;
                int disB = dijkstras(previousDay, b, graph) + dijkstras(b, a, graph) + previousCost;
                newCases.emplace_back(make_pair(b, disA));
                newCases.emplace_back(make_pair(a, disB));
            }
        }
        previousCases = newCases;
    }
    int minDis = INT_MAX;
    for (int i = 0; i < previousCases.size(); i++){
        if (previousCases[i].second < minDis){
            minDis = previousCases[i].second;
        }
    }
    cout << minDis;
}
