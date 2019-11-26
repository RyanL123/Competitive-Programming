#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main() {
    //get number of edges and vertices
    int n, m;
    cin >> n >> m;

    //initialize not visited array and shortest path array
    bool notVisited[1010];
    int sp[1010];
    for (int i = 0; i < 1010; i++){
        notVisited[i] = true;
        sp[i] = INT_MAX;
    }
    sp[1] = 0;

    //initialize graph with adjacency matrix
    vector<pair<int,int>> graph[1010];
    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(w, v));
        graph[v].push_back(make_pair(w, u));
    }

    //initialize priority queue with node 1
    priority_queue<pair<int, int>> q;
    q.push(make_pair(0, 1));

    //dijkstra's
    while (!q.empty()){
        //record top element and pop it
        int w = -q.top().first;
        int v = q.top().second;
        q.pop();

        //set the node as visited
        notVisited[v] = false;

        //if the weight to the node is greater than the shortest path there, skip
        if (w > sp[v]){
            continue;
        }

        //iterate through every node the node is connected to
        for (int i = 0; i < graph[v].size(); i++){
            /*only visit a node if it has not been visited before, since
            we guarantee that the first time we visit a node we get the
            shortest distance to that node*/
            int weight = graph[v][i].first;
            int node = graph[v][i].second;
            if (notVisited[node] && sp[node] >= weight+w){
                sp[node] = weight+w;
                q.push(make_pair(-(weight+w), node));
            }
        }
    }
    for (int i = 1; i <= n; i++){
        if (sp[i] == INT_MAX){
            cout << -1 << endl;
        }
        else{
            cout << sp[i] << endl;
        }
    }
}
