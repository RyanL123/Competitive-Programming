#include <cstdio>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

unsigned long long getDistance(pair<int, int> c1, pair<int, int> c2){
    int x1 = c1.first;
    int y1 = c1.second;
    int x2 = c2.first;
    int y2 = c2.second;
    return (pow(x2-x1, 2) + pow(y2-y1, 2));
}

// Binary search to answer query
int query(unsigned long long sp[], unsigned long long q, int n){
    int count = 0, left = 1, right = n+1;
    if (q >= sp[n]){
        return n;
    }
    while (left <= right){
        int mid = (left+right)/2;
        if (sp[mid] <= q){
            count = mid;
            left = mid+1;
        }
        else {
            right = mid-1;
        }
    }
    return count;
}

// Graph represented using adjacency matrix
unsigned long long graph[3010][3010];
unsigned long long sp[3010];
bool notVisited[3010];
pair<int, int> cords[3010];
int main() {
    int n, x, y, source;
    scanf("%i", &n);
    // Get coordinates of cities
    for (int i = 1; i <= n; i++){
        scanf("%i%i", &x, &y);
        cords[i] = make_pair(x, y);
        // Initialize shortest path and not visited array
        sp[i] = LONG_LONG_MAX;
        notVisited[i] = true;
    }
    scanf("%i", &source);
    sp[source] = 0;

    // Initialize graph
    for (int i = 0; i < 3010; i++){
        for (int j = 0; j < 3010; j++){
            graph[i][j] = -1;
        }
    }

    //Construct complete graph
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            // Avoids adding a node connecting to itself
            if (j != i){
                unsigned long long distance = getDistance(cords[i], cords[j]);
                graph[j][i] = distance;
            }
        }
    }

    //Dijkstra's O(n^2) implementation
    int u;
    while (true) {
        unsigned long long z = LONG_LONG_MAX;
        u = -1;
        for (int i = 1; i <= n; i++){
            if (notVisited[i] && z >= sp[i]) {
                z = sp[i];
                u = i;
            }
        }
        if (u == -1) break;
        notVisited[u] = false;
        for (int i = 1; i <= n; i++){
            if (graph[u][i] != -1){
                if (sp[i] > sp[u] + graph[u][i]){
                    sp[i] = sp[u] + graph[u][i];
                }
            }

        }
    }

    sort(sp+1, sp+n+1);
    int queries;
    unsigned long long q;
    scanf("%i", &queries);
    for (int i = 0; i < queries; i++){
        scanf("%llu", &q);
        printf("%i\n", query(sp, q, n));
    }
}