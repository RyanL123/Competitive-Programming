#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define srt(x) sort(x.begin(), x.end())
#define inf 0x3f3f3f3f

const int MM = 3e5+5;

int table[MM][20]; // Precomputed list of parents for every node up to log N = 19
int dis[MM]; // Distance from root
int val[MM]; // Top value of the current stack

// LCA with binary lifting
int lca(int u, int v){
    if (dis[u] < dis[v]) swap(u, v);
    // get u and v to the same level from root
    for (int i = 19; i >= 0; i--){
        if (dis[u] - pow(2, i) >= dis[v]){
            u = table[u][i];
        }
    }
    // LCA of u and v is u or v
    if (u == v) return v;
    // Keep trying the largest power of 2 such that the parents of the two nodes are not equal
    // The parent of the two node will always be too short of the LCA
    // This will guarantee we will approach the LCA in logn time
    for (int i = 19; i >= 0; i--){
        if (table[u][i] != table[v][i]){
            u = table[u][i], v = table[v][i];
        }
    }
    // LCA is the immediate parent of either node
    return table[u][0];
}

// Kinda copied official solution but at least I understand the process
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    table[0][0] = -1;
    for (int i = 1; i <= n; i++){
        char c;
        int v;
        cin >> c >> v;
        v = val[v];
        if (c == 'a'){
            val[i] = i; // Top value of current stack = i
            dis[i] = dis[v]+1; // Distance from root = distance of parent + 1
            // Pre compute parents using sparse table
            table[i][0] = v;
            for (int j = 1; j <= 19; j++){
                if (table[i][j-1] != -1) table[i][j] = table[table[i][j-1]][j-1];
            }
        }
        else if (c == 'b'){
            cout << v << "\n";
            val[i] = table[v][0];
        }
        else {
            int w;
            cin >> w;
            w = val[w];
            val[i] = v;
            cout << dis[lca(v, w)] << "\n";
        }
    }
}