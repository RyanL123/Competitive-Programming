#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define inf 0x3f3f3f3f

vi graph[100010];

int dfs(int node, int nodes){
    if (graph[node].empty()) return nodes;
    return dfs(graph[node][0], nodes+1);
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int Q;
    cin >> Q;
    int prev = -1;
    for (int i = 1; i <= Q; i++){
        int q;
        cin >> q;
        if (q == 1){
            prev = i;
        }
        else if (q == 2){
            graph[prev].pb(i);
            prev = i;
        }
        else if (q == 3){
            int x;
            cin >> x;
            if (dfs(x, 0)%2 == 1){
                cout << 0 << "\n";
            }
            else cout << 1 << "\n";
        }
    }
}