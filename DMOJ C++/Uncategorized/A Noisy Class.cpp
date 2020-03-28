#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef long long ll;
typedef unsigned long long ull;
#define pb(x) push_back(x)
#define inf INT_MAX

int inDeg[10010];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> graph[n+10];
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        if (find(graph[a].begin(), graph[a].end(), b) == graph[a].end()){
            inDeg[b]++;
            graph[a].pb(b);
        }
    }
    int count = 0;
    while (true){
        bool flag = false;
        for (int i = 1; i <= n; i++){
            if (inDeg[i] == 0){
                flag = true;
                inDeg[i]--;
                count++;
                for (int j = 0; j < graph[i].size(); j++){
                    inDeg[graph[i][j]]--;
                }
            }
        }
        if (!flag) break;
    }
    if (count == n){
        cout << "Y";
    }
    else {
        cout << "N";
    }
}