#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <utility>
#include <queue>
#include <set>

using namespace std;

long long room[1010][1010];
bool visited[1010][1010];
bool usedX[1000010];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            int a;
            cin >> a;
            room[i][j] = a;
            visited[i][j] = false;
        }
    }
    visited[1][1] = true;
    queue<pair<long long, long long>> q;
    q.push(make_pair(1,1));

    usedX[1] = true;
    while (!q.empty()){
        long long a = q.front().first;
        long long b = q.front().second;
        q.pop();
        long long x = room[a][b];
        for (int i = 1; i <= ceil(sqrt(x)); i++){
            if (x%i == 0){
                int v1 = x/i;
                int v2 = i;
                if (v1 == m && v2 == n){
                    cout << "yes" << endl;
                    return 0;
                }
                else if (v1 == n && v2 == m){
                    cout << "yes" << endl;
                    return 0;
                }
                if (v1 <= m && v2 <= n && !visited[v1][v2]){
                    if (!usedX[room[v1][v2]]){
                        usedX[room[v1][v2]] = true;
                        q.push(make_pair(v1,v2));
                        visited[v1][v2] = true;
                    }
                }
                if (v2 <= m && v1 <= n && !visited[v2][v1]){
                    if (!usedX[room[v2][v1]]) {
                        usedX[room[v2][v1]] = true;
                        q.push(make_pair(v2, v1));
                        visited[v2][v1] = true;
                    }
                }
            }
        }
    }
    if (visited[m][n]){
        cout << "yes" << endl;
    }
    else {
        cout << "no" << endl;
    }
}
