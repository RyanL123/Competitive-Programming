#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

//find with path compression
int find(int parent[], int v){
    if (parent[v] == v){
        return v;
    }
    else{
        return (parent[v] = find(parent, parent[v]));
    }
}

//union by rank
void unionSet(int parent[], int rank[], int pb, int pe){
    //changes parent and rank
    if (parent[pb] == parent[pe]){
        parent[pb] = pe;
        rank[pe]++;
    }
    parent[pb] < parent[pe] ? parent[pb] = pe : parent[pe] = pb;
}

int main() {
    int n, k, total = 0, counter = 0;
    scanf("%i%i", &n, &k);
    int rank[n+1], parent[n+1];
    vector<tuple<int,int,int>> edge;

    //initialize parent & rank
    for (int i = 1; i <= n; i++){
        rank[i] = 0;
        parent[i] = i;
    }

    //get edges and cost
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
    int it = 0;
    //Kruskal's
    while (true){
        int bv = get<1>(edge[it]);
        int ev = get<2>(edge[it]);

        //find the parents of beginning vertex and end vertex
        int pb = find(parent, bv);
        int pe = find(parent, ev);

        //if edge doesnt form a cycle, add the edge to graph and increase total cost
        if (pb != pe){
            unionSet(parent, rank, pb, pe);
            total += get<0>(edge[it]);
            counter++;
        }
        it++;
        //break when tree is formed
        if (counter == n-1){
            break;
        }
    }
    printf("%i", total);
}