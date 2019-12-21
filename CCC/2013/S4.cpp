#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main() {
    int n, m, p, q;
    cin >> n >> m;
    vector<vector<int>> graph;
    int visited[1000000] {0};
    for (int i = 0; i < n; i++){
        graph.push_back({});
    }
    for (int i = 0; i < m; i++){
        cin >> p >> q;
        graph[p].push_back(q);
    }

    //bfs to determine if q is shorter than p
    cin >> p >> q;
    queue<int> queue1;
    queue1.push(p);
    visited[p] = 1;
    bool QPartOfP = false;
    while (!queue1.empty()){
        int front = queue1.front();
        queue1.pop();
        for (int i = 0; i < graph[front].size(); i++){
            if (graph[front][i] == q){
                QPartOfP = true;
                break;
            }
            if (visited[graph[front][i]] == 0){
                queue1.push(graph[front][i]);
                visited[graph[front][i]] = 1;
            }
        }
    }

    //bfs to determine if p is shorter than q
    int visited2[1000000] {0};
    queue<int> queue2;
    queue2.push(q);
    bool PPartOfQ = false;
    visited2[q] = 1;
    while (!queue2.empty()){
        int front = queue2.front();
        queue2.pop();
        for (int i = 0; i < graph[front].size(); i++){
            if (graph[front][i] == p){
                PPartOfQ = true;
                break;
            }
            if (visited2[graph[front][i]] == 0){
                queue2.push(graph[front][i]);
                visited2[graph[front][i]] = 1;
            }
        }
    }

    //if one is taller than the other and the inverse is false, then there is enough
    //information to determine the result. If both people are not related, then there
    //is not enough information to determine the result
    if (PPartOfQ and !QPartOfP){
        cout << "no";
    }
    else if (QPartOfP and !PPartOfQ){
        cout << "yes";
    }
    else{
        cout << "unknown";
    }
}

