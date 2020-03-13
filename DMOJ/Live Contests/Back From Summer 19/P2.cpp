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

int steps[1010][1010];
string graph[1010];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> graph[i];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            steps[i][j] = inf;
        }
    }
    queue<pii> q;
    q.push(mp(0,0));
    steps[0][0] = 0;
    while (!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        if (graph[r+1][c] != '#' && steps[r+1][c] > steps[r][c]+1){
            steps[r+1][c] = steps[r][c]+1;
            q.push(mp(r+1, c));
        }
        if (graph[r][c+1] != '#' && steps[r][c+1] > steps[r][c]+1){
            steps[r][c+1] = steps[r][c]+1;
            q.push(mp(r, c+1));
        }
        if (graph[r][c-1] != '#' && steps[r][c-1] > steps[r][c]+1){
            steps[r][c-1] = steps[r][c]+1;
            q.push(mp(r, c-1));
        }
    }
    if (steps[n-1][n-1] == inf){
        cout << -1 << endl;
    }
    else {
        int x = steps[n-1][n-1]/2 - n + 1;
        ll ans = pow(n-1, 2) + pow(x, 2) + pow(n-1+x, 2);
        cout << ans << endl;
    }
}
