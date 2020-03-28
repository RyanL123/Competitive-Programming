#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef long long ll;
typedef unsigned long long ull;
#define pb(a, b) push_back(a, b)
#define eb(a, b) emplace_back(a, b)
#define inf INT_MAX

bool graph[30][30];
int steps[30][30];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int r, c, k;
    cin >> r >> c >> k;
    while (k--){
        int a, b;
        cin >> a >> b;
        graph[a][b] = true;
    }
    for (int i = 1; i <= c; i++){
        if (!graph[1][i]){
            steps[1][i] = 1;
        }
        else {
            break;
        }
    }
    for (int i = 1; i <= r; i++){
        if (!graph[i][1]){
            steps[i][1] = 1;
        }
        else {
            break;
        }
    }
    for (int i = 2; i <= r; i++){
        for (int j = 2; j <= c; j++){
            if (graph[i][j]){
                steps[i][j] = 0;
            }
            else {
                steps[i][j] = steps[i-1][j] + steps[i][j-1];
            }
        }
    }
    cout << steps[r][c] << endl;
}