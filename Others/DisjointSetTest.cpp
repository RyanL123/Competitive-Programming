#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int find(int parent[], int v){
    if (parent[v] == v){
        return v;
    }
    return find(parent, parent[v]);
}

void unionSet(int parent[], int rank[], int bv, int ev){
    int pb = find(parent, bv);
    int pe = find(parent, ev);

    //changes parent and rank
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
    int vertex, edge, parentCount = 0;
    scanf("%i%i", &vertex, &edge);
    int parent[vertex+1], rank[vertex+1];
    vector<int> output;
    pair<int,int> edgesArray[edge+1];

    //get every edge with cost and store them as pairs
    for (int i = 1; i <= edge; i++){
        int bv, ev;
        scanf("%i%i", &bv, &ev);
        edgesArray[i] = make_pair(bv,ev);
    }

    //initialize parents and ranks
    for (int i = 1; i <= vertex; i++){
        parent[i] = i;
        rank[i] = 1;
    }

    //Kruskal's
    for (int i = 1; i <= edge; i++){
        int bv = edgesArray[i].first;
        int ev = edgesArray[i].second;

        //find the parents of beginning vertex and end vertex
        int pb = find(parent, bv);
        int pe = find(parent, ev);

        //if edge doesnt form a cycle, add the edge to graph
        if (pb != pe){
            unionSet(parent, rank, bv, ev);
            output.push_back(i);
        }

        if (output.size() == vertex-1){
            break;
        }
    }

    //checks if the graph is disconnected
    for (int i = 1; i < vertex; i++){
        if (parent[i] == i){
            parentCount++;
        }
    }

    if (parentCount > 1){
        printf("Disconnected Graph");
    }
    else{
        for (int i = 0; i < output.size(); i++) {
            printf("%i\n", output[i]);
        }
    }
}