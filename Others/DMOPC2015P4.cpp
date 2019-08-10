#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int find(int parent[], int v){
    if (parent[v] == v){
        return v;
    }
    return find(parent, parent[v]);
}

void unionSet(int parent[], int rank[], int  bv, int ev){
    int pb = find(parent, bv);
    int pe = find(parent, ev);

    if (rank[pb] < rank[pe]){
        parent[pb] = pe;
        rank[pe] += rank[pb];
    }
    else{
        parent[pe] = pb;
        rank[pb] += rank[pe];
    }
}
int main() {
    int n, k, total = 0;
    scanf("%i%i", &n, &k);
    int rank[n+1], parent[n+1];
    vector<tuple<int,int,int>> edge;

    //initialize parent & rank
    for (int i = 1; i <= n; i++){
        rank[i] = 1;
        parent[i] = i;
    }

    for (int i = 1; i < n; i++){
        int weight;
        scanf("%i", &weight);
        //adds the edge as a tuple
        edge.push_back(make_tuple(weight, i, i+1));
        if (i+k <= n && i+k >= 0){
            edge.push_back(make_tuple(0, i, i+k));
        }
    }
    //sort by weight
    sort(edge.begin(), edge.end());
    //Kruskal's
    for (int i = 0; i < n; i++){
        int bv = get<1>(edge[i]);
        int ev = get<2>(edge[i]);

        //find the parents of beginning vertex and end vertex
        int pb = find(parent, bv);
        int pe = find(parent, ev);

        //if edge doesnt form a cycle, add the edge to graph and increase total cost
        if (pb != pe){
            unionSet(parent, rank, bv, ev);
            total += get<0>(edge[i]);
        }
    }
    printf("%i", total);
}