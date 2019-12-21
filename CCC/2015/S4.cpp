#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <climits>

using namespace std;

vector<tuple<int, int, int>> graph[2010];
int sp[2010];
int hull[2010];
bool notVisited[2010];

int main() {
    int k, n, m;
    cin >> k >> n >> m;
    //initialize graph
    for (int i = 1; i < m; i++) {
        int a, b, time, hullCost;
        cin >> a >> b >> time >> hullCost;
        graph[a].emplace_back(make_tuple(time, b, hullCost));
        graph[b].emplace_back(make_tuple(time, a, hullCost));
    }

    //initialize minimum cost array and not visited array
    for (int i = 0; i < 2010; i++) {
        sp[i] = INT_MAX;
        notVisited[i] = true;
        hull[i] = INT_MAX;
    }
    // get start and end
    int start, end;
    cin >> start >> end;

    //initialize starting node
    sp[start] = 0;
    notVisited[start] = false;
    hull[start] = 0;

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
        notVisited[node] = false;
        q.pop();

        // if the cost is bigger than the node it connects to, ignore it.
        if (time > sp[node]) continue;

        // iterate through every node connected
        for (int i = 0; i < graph[node].size(); i++) {
            // node has not been visited
            if (notVisited[get<1>(graph[node][i])]) {
                // if there is a shorter path to the node, update the cost
                if (sp[get<1>(graph[node][i])] >= get<0>(graph[node][i]) + time &&
                    hull[get<1>(graph[node][i])] + hullCost < k) {
                    // update new shortest path and hull cost
                    hull[get<1>(graph[node][i])] = get<2>(graph[node][i]) + hullCost;
                    sp[get<1>(graph[node][i])] = get<0>(graph[node][i]) + time;

                    // push the new node
                    q.push(make_tuple(-get<0>(graph[node][i]) + time,
                                      get<1>(graph[node][i]),
                                      get<2>(graph[node][i]) + hullCost));
                }
            }
        }
    }
    if (hull[end] > k) {
        cout << -1;
    }
    else {
        cout << sp[end];
    }
}