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

bool prioritize(const tuple<int, int, int, int>& a, const tuple<int, int, int, int>& b){
    if (get<0>(a) == get<0>(b)){
        if (get<3>(a) > get<3>(b)) return true;
        else return false;
    }
    return get<0>(a) < get<0>(b);
}

int main() {
    int n, m, d, days = 0, heaviest = -1;
    bool used = false;
    scanf("%i%i%i", &n, &m, &d);
    int parent[n+1], rank[n+1];
    vector<tuple<int, int, int, int>> edges, notAccepted;

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
            if (cost > heaviest){
                heaviest = cost;
            }
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
        int cost = get<0>(edges[i]);
        int bv = get<1>(edges[i]);
        int ev = get<2>(edges[i]);
        int pb = find(parent, bv);
        int pe = find(parent, ev);

        //won't form a cycle
        if (pb != pe){
            if (cost < heaviest || (cost == heaviest && get<3>(edges[i]) == 1)){

            }
            else {
                continue;
            }
            //check if the current edge is already part of the plan
            if (get<3>(edges[i]) == 0){
                days++;
            }
            unionSet(parent, rank, pb, pe);
        }
        else{
            notAccepted.push_back(edges[i]);
        }
    }
    sort(notAccepted.begin(), notAccepted.end(), prioritize);
    for (int i = 0; i < notAccepted.size(); i++){
        if (get<0>(notAccepted[i]) < d && get<3>(notAccepted[i]) == 1){
            days--;
            break;
        }
    }
    printf("%i", days);
}