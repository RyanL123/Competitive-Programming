#include <iostream>
#include <cstdio>
#include <tuple>
#include <vector>
#include <algorithm>

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
int main() {
    int vertex, edge, destination, placed = 0;
    vector<tuple<int,int,int>> edges;
    scanf("%i%i%i", &vertex, &edge, &destination);
    int rank[vertex+1], parent[vertex+1];

    //take input and sort by weight
    for (int i = 1; i <= edge; i++){
        int v1, v2, c;
        scanf("%i%i%i", &v1, &v2, &c);
        edges.push_back(make_tuple(c,v1,v2));
    }
    sort(edges.begin(), edges.end(), greater<int>());

    //initialize parent and rank
    for (int i = 1; i <= vertex; i++){
        rank[i] = 0;
        parent[i] = i;
    }

    //Max spanning tree using kruskal's
    for (int i = 0; i < edge; i++){
        int pb = find(parent, get<1>(edges[i]));
        int pe = find(parent, get<2>(edges[i]));
        if (pb != pe){
            unionSet(parent, rank, pb, pe);
            placed++;
        }
        if (placed == vertex-1) break;
    }
}