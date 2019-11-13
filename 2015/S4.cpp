#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <climits>

using namespace std;

vector<tuple<int, int, int>> graph[2010];
int min_cost[2010];
int hull[2010];
bool notVisited[2010];
int main() {
    int k, n, m;
    cin >> k >> n >> m;
    //initialize graph
    for (int i = 1; i < m; i++){
        int a, b, time, hull;
        cin >> a >> b >> time >> hull;
        graph[a].emplace_back(make_tuple(time, b, hull));
        graph[b].emplace_back(make_tuple(time, a, hull));
    }
    //initialize minimum cost array and not visited array
    for (int i = 0; i < 2010; i++){
        min_cost[i] = INT_MAX;
        notVisited[i] = true;
        hull[i] = -1;
    }
    // get start and end
    int start, end;
    cin >> start >> end;

    //initialize priority queue
    priority_queue<tuple<int, int, int>> q;
    q.push(make_tuple(0, start, 0));

    //dijkstras
    while (!q.empty()){
        tuple<int, int, int> front = q.top();
        int time = get<0>(front);
        int node = get<1>(front);
        int hullCost = get<2>(front);
        for (int i = 0; i < graph[node].size(); i++){
            if (notVisited[get<1>(graph[node][i])] && min_cost[get<1>(graph[node][i])] ){

            }
        }
    }
}