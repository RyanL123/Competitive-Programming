#include <iostream>
#include <cstdio>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int find(int parent[], int v){
    if (parent[v] == v) return v;
    return (parent[v] = find(parent, parent[v]));
}

void unionSet(int parent[], int rank[], int pb, int pe){
    if (rank[pb] == rank[pe]){
        rank[pe]++;
        parent[pb] = pe;
    }
    else {
        parent[pb] < parent[pe] ? parent[pb] = pe : parent[pe] = pb;
    }
}

int main() {
    int n, m, d, days = 0;
    scanf("%i%i%i", &n, &m, &d);
    int parent[n+1], rank[n+1];
    vector<tuple<int, int, int>> edges;
    vector<tuple<int, int, int>> currentPlan;
    vector<int> graph[n+1];

    //initialize parent and rank
    for (int i = 1; i <= n; i++){
        parent[i] = i;
        rank[i] = 0;
    }

    //get edges
    for (int i = 1; i <= m; i++){
        int start, end, cost;
        scanf("%i%i%i", &start, &end, &cost);
        //current plan
        if (i <= n-1){
            currentPlan.push_back(make_tuple(cost, start, end));
            graph[start].push_back(end);
            graph[end].push_back(start);
        }
        else {
            edges.push_back(make_tuple(cost, start, end));
        }
    }

    //apply pipe enhancer to highest cost pipe in active plan
    sort(currentPlan.begin(), currentPlan.end());
    get<0>(currentPlan[currentPlan.size()-1]) = max(0, get<0>(currentPlan[currentPlan.size()-1])-d);
    for (int i = 0; i < currentPlan.size(); i++){
        edges.push_back(currentPlan[i]);
    }
    //sort edges for MST
    sort(edges.begin(), edges.end());

    for (int i = 0; i < edges.size(); i++){
        int bv = get<1>(edges[i]);
        int ev = get<2>(edges[i]);
        int pb = find(parent, bv);
        int pe = find(parent, ev);

        if (pb != pe){
            //check if the current edge is already part of the plan
            if (graph[bv][0] != ev && graph[ev][0] != bv){
                days++;
            }
            unionSet(parent, rank, pb, pe);
        }
    }
    printf("%i", days);
}