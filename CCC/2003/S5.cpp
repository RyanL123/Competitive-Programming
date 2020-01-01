#include <iostream>
#include <cstdio>
#include <tuple>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int find(int parent[], int v){
    if (parent[v] == v) return v;
    return parent[v] = find(parent, parent[v]);
}

void unionSet(int parent[], int rank[], int pb, int pe){
    if (parent[pb] == parent[pe]){
        parent[pb] = pe;
        rank[pe]++;
    }
    parent[pb] < parent[pe] ? parent[pb] = pe : parent[pe] = pb;
}

int maxW[10010];
int main() {
    int vertex, edge, destination, placed = 0, min = 1000000;
    vector<tuple<int,int,int>> edges;
    scanf("%i%i%i", &vertex, &edge, &destination);
    int rank[vertex+1], parent[vertex+1];
    vector<pair<int,int>> graph[vertex+1];
    vector<int> desCities;


    //take input and sort by weight
    for (int i = 1; i <= edge; i++){
        int v1, v2, c;
        scanf("%i%i%i", &v1, &v2, &c);
        edges.push_back(make_tuple(c,v1,v2));
    }
    sort(edges.begin(), edges.end());

    //initialize parent and rank
    for (int i = 1; i <= vertex; i++){
        rank[i] = 0;
        parent[i] = i;
    }

    for (int i = 1; i <= destination; i++){
        int input;
        scanf("%i", &input);
        desCities.push_back(input);
    }

    //Max spanning tree using kruskal's
    for (int i = edge-1; i >= 0; i--){
        int pb = find(parent, get<1>(edges[i]));
        int pe = find(parent, get<2>(edges[i]));
        if (pb != pe){
            unionSet(parent, rank, pb, pe);
            placed++;
            graph[get<1>(edges[i])].push_back(make_pair(get<0>(edges[i]), get<2>(edges[i])));
            graph[get<2>(edges[i])].push_back(make_pair(get<0>(edges[i]), get<1>(edges[i])));
        }
        if (placed == vertex-1) break;
    }

    //BFS to find min weight that can be driven through all cities
    bool visited[10010] {false};
    queue<pair<int, int>> q;
    visited[1] = true;
    q.push(make_pair(min, 1));
    while (!q.empty()){
        int w = q.front().first;
        int node = q.front().second;
        q.pop();
        for (int i = 0; i < graph[node].size(); i++){
            if (!visited[graph[node][i].second]){
                q.push(make_pair(graph[node][i].first, graph[node][i].second));
                visited[graph[node][i].second] = true;
                //If the weight to get to the next city is lower than
                //the weight that is used to get to this city,
                //lower the weight cap
                if (graph[node][i].first < w){
                    maxW[graph[node][i].second] = graph[node][i].first;
                }
                //Otherwise the weight cap remains the same
                else {
                    maxW[graph[node][i].second] = w;
                }
            }
        }
    }

    //Find min
    for (int i = 0; i < desCities.size(); i++){
        if (maxW[desCities[i]] < min){
            min = maxW[desCities[i]];
        }
    }
    printf("%i", min);
}