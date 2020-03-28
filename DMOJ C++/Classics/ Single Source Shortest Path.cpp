#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> graph[1010];
    bool notVisited[1010];
    int distance[1010];
    //initialize distance and not visited
    for (int i = 0; i < 1010; i++){
        notVisited[i] = true;
        distance[i] = INT_MAX;
    }
    //initialize graph
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(w, v));
        graph[v].push_back(make_pair(w, u));
    }
    //initialize starting node
    distance[1] = 0;
    notVisited[0] = false;

    //initialize priority queue
    priority_queue<pair<int, int>> q;
    q.push(make_pair(0, 1));

    //dijkstra's
    while (!q.empty()){
        pair<int, int> u = q.top();
        q.pop();
        //loop through every vertex connected to the top vertex
        for (int i = 0; i < graph[u.second].size(); i++){
            pair<int, int> v = graph[u.second][i];
            // if there is a shorter distance to the vertex, update it and push it into the queue
            if (distance[v.second] > distance[u.second] + v.first){
                distance[v.second] = distance[u.second] + v.first;
                q.push(make_pair(v.first, v.second));
            }
        }
    }
    for (int i = 1; i <= n; i++){
        if (distance[i] == INT_MAX){
            cout << -1 << endl;
        }
        else{
            cout << distance[i] << endl;
        }
    }
}