#include <iostream>
#include <cstdio>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int find(int parent[], int v){
    if (parent[v] == v) return v;
    return parent[v] = find(parent, parent[v]);
}

void unionSet(int parent[], int rank[], int pb, int pe){
    if (rank[pb] == rank[pe]){
        rank[pe]++;
        parent[pb] = pe;
    }
    else if (rank[pb] > rank[pe]) {
        parent[pe] = parent[pb];
        rank[pb] += rank[pe];
    }
    else {
        parent[pb] = parent[pe];
        rank[pe] += parent[pb];
    }
}

// Prioritize edges that are in the current plan
bool prioritize(const tuple<int, int, int, int>& a, const tuple<int, int, int, int>& b){
    if (get<0>(a) == get<0>(b)){
        return get<3>(a) > get<3>(b);
    }
    return get<0>(a) < get<0>(b);
}

int main() {
    int n, m, d, days = 0, heaviest, heaviestWeight;
    scanf("%i%i%i", &n, &m, &d);
    int parent[n+1], rank[n+1];
    vector<tuple<int, int, int, int>> edges;

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
            edges.push_back(make_tuple(cost, start, end, 1));
        }
        //inactive edges
        else {
            edges.push_back(make_tuple(cost, start, end, 0));
        }
    }

    //sort edges for MST, prioritizing pipes in the current plan
    sort(edges.begin(), edges.end(), prioritize);

    //Kruskal's
    for (int i = 0; i < m; i++){
        int bv = get<1>(edges[i]);
        int ev = get<2>(edges[i]);
        int pb = find(parent, bv);
        int pe = find(parent, ev);

        //won't form a cycle
        if (pb != pe){
            if (get<3>(edges[i]) == 0){
                days++;
            }
            heaviest = get<3>(edges[i]);
            heaviestWeight = get<0>(edges[i]);
            unionSet(parent, rank, pb, pe);
        }
    }
    // Heaviest edge not part of current plan
    // Rerun Kruskals again
    if (heaviest == 0){
        for (int i = 1; i <= n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
        for (int i = 0; i < m; i++){
            int cost = get<0>(edges[i]);
            int bv = get<1>(edges[i]);
            int ev = get<2>(edges[i]);
            int pb = find(parent, bv);
            int pe = find(parent, ev);
            if (pb != pe){
                // Days cannot be reduced
                if (cost < heaviestWeight || (cost == heaviestWeight && get<3>(edges[i]) == 1)){
                    unionSet(parent, rank, pb, pe);
                }
                // Is old edge and can be reduced
                else if (cost <= d && get<3>(edges[i]) == 1){
                    printf("%i", days-1);
                    return 0;
                }
            }
        }
    }
    printf("%i", days);
}