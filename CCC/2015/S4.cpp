#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <climits>

using namespace std;

vector<tuple<int, int, int>> graph[2010];
int sp[2010][2010];

int main() {
    int k, n, m;
    cin >> k >> n >> m;
    //initialize graph
    for (int i = 0; i < m; i++) {
        int a, b, time, hullCost;
        cin >> a >> b >> time >> hullCost;
        graph[a].emplace_back(make_tuple(time, b, hullCost));
        graph[b].emplace_back(make_tuple(time, a, hullCost));
    }

    //initialize shortest path array
    for (int i = 0; i < 2010; i++){
        for (int j = 0; j < 2010; j++){
            sp[i][j] = INT_MAX;
        }
    }
    // get start and end
    int start, end;
    cin >> start >> end;

    //initialize starting node
    for (int i = 0; i < 2010; i++){
        sp[start][i] = 0;
    }

    //initialize priority queue
    priority_queue<tuple<int, int, int>> q;
    q.push(make_tuple(0, start, 0));

    //dijkstra's
    while (!q.empty()) {
        tuple<int, int, int> front = q.top();
        // record node and pop it. Set it as visited
        int time = -get<0>(front);
        int node = get<1>(front);
        int hullCost = get<2>(front);
        q.pop();

        // There is a shorter way to get to this node, continue
        if (time > sp[node][hullCost]) continue;

        // iterate through every node connected
        for (int i = 0; i < graph[node].size(); i++) {
            // node has not been visited
            int connectedTime = get<0>(graph[node][i]);
            int connectedNode = get<1>(graph[node][i]);
            int connectedCost = get<2>(graph[node][i]);
            // if there is a shorter path to the node, update the cost
            if (sp[connectedNode][hullCost+connectedCost] >= time+connectedTime){
                //Hull cost is more than current hull, continue
                if (hullCost + connectedCost >= k) continue;
                // Update time to get to node at current hull cost and push into queue
                sp[connectedNode][hullCost+connectedCost] = sp[node][hullCost]+connectedTime;
                q.push(make_tuple(-(connectedTime+time), connectedNode, connectedCost+hullCost));
            }
        }
    }
    int lowest = INT_MAX;
    //Shortest distance while maintaining the required hull cost
    for (int i = 0; i < k; i++){
        if (sp[end][i] < lowest){
            lowest = sp[end][i];
        }
    }
    if (lowest == INT_MAX){
        cout << -1;
    }
    else {
        cout << lowest;
    }
}