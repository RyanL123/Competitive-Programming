#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>

using namespace std;

bool BFS(vector<int> g[], int start, int end){
    queue<int> q;
    bool visited[30] {false};
    visited[start] = true;
    q.push(start);
    while (!q.empty()){
        int node = q.front();
        q.pop();
        for (int i = 0; i < g[node].size(); i++){
            if (!visited[g[node][i]]){
                q.push(g[node][i]);
                visited[g[node][i]] = true;
            }
        }
    }
    return visited[end];
}

void removeEdge(vector<int> g[], int bv, int ev){
    g[bv].erase(find(g[bv].begin(), g[bv].end(), ev));
    g[ev].erase(find(g[ev].begin(), g[ev].end(), bv));
}

void addEdge(vector<int> g[], int bv, int ev){
    g[bv].push_back(ev);
    g[ev].push_back(bv);
}

int main() {
    vector<int> graph[30];
    vector<pair<int, int>> edges;
    string input;
    int roadCount = 0;
    //Construct graph
    while (cin >> input){
        if (input == "**") break;
        //A = 1 Z = 26
        graph[input[0]-64].push_back(input[1]-64);
        graph[input[1]-64].push_back(input[0]-64);
        edges.push_back(make_pair(input[0]-64, input[1]-64));
    }
    for (int i = 0; i < edges.size(); i++){
        //Test if disconnecting the current edge will break the path
        removeEdge(graph, edges[i].first, edges[i].second);
        if (!BFS(graph, 1, 2)){
            char bv = (char)(edges[i].first+64);
            char ev = (char)(edges[i].second+64);
            cout << bv << ev << endl;
            roadCount++;
        }
        addEdge(graph, edges[i].first, edges[i].second);
    }
    printf("There are %i disconnecting roads.\n", roadCount);
}
