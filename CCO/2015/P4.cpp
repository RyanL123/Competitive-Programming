#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef long long ll;
typedef unsigned long long ull;
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define inf INT_MAX

string parking[2010];
vii graph[2010][2010];
int outDeg[2010][2010];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int cars = 0;
    for (int i = 0; i < n; i++){
        cin >> parking[i];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (parking[i][j] == 'N'){
                int it = i-1;
                bool firstCar = true;
                while (it >= 0){
                    if (parking[it][j] != '.'){
                        if (firstCar){
                            graph[it][j].pb(mp(i, j));
                            firstCar = false;
                        }
                        outDeg[i][j]++;
                    }
                    it--;
                }
                cars++;
            }
            else if (parking[i][j] == 'S'){
                int it = i+1;
                bool firstCar = true;
                while (it < n){
                    if (parking[it][j] != '.'){
                        if (firstCar){
                            graph[it][j].pb(mp(i, j));
                            firstCar = false;
                        }
                        outDeg[i][j]++;
                    }
                    it++;
                }
                cars++;
            }
            else if (parking[i][j] == 'W'){
                int it = j-1;
                bool firstCar = true;
                while (it >= 0){
                    if (parking[i][it] != '.'){
                        if (firstCar){
                            graph[i][it].pb(mp(i, j));
                            firstCar = false;
                        }
                        outDeg[i][j]++;
                    }
                    it--;
                }
                cars++;
            }
            else if (parking[i][j] == 'E'){
                int it = j+1;
                bool firstCar = true;
                while (it < m){
                    if (parking[i][it] != '.'){
                        if (firstCar){
                            graph[i][it].pb(mp(i, j));
                            firstCar = false;
                        }
                        outDeg[i][j]++;
                    }
                    it++;
                }
                cars++;
            }
        }
    }
    queue<pii> q;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (parking[i][j] != '.' && outDeg[i][j] == 0){
                q.push(mp(i,j));
            }
        }
    }
    int count = 0;
    while (!q.empty()){
        pii node = q.front();
        q.pop();
        outDeg[node.first][node.second]--;
        cout << "(" << node.first << "," << node.second << ")\n";
        count++;
        for (int l = 0; l < graph[node.first][node.second].size(); l++){
            pii children = graph[node.first][node.second][l];
            outDeg[children.first][children.second]--;
            if (outDeg[children.first][children.second] == 0){
                q.push(mp(children.first, children.second));
            }
        }
    }
}
