#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> graph[10][9];
unsigned long long values[10][9];

unsigned long long dfs(int x, int y, bool visited[10][9]){
    if (visited[x][y] && values[x][y] == -1){
        return 10000000000;
    }
    if (values[x][y] != -1){
        return values[x][y];
    }
    if (graph[x][y].empty()){
        return values[x][y];
    }
    visited[x][y] = true;
    unsigned long long total = 0;
    for (int i = 0; i < graph[x][y].size(); i++){
        total += dfs(graph[x][y][i].first, graph[x][y][i].second, visited);
    }
    values[x][y] = total;
    return total;
}

int main(){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 9; j++){
            string s;
            cin >> s;
            if (s.length() == 1){
                values[i][j] = s[0]-48;
            }
            else if (isdigit(s[0])){
                for (int k = 1; k <= s.length(); k++){
                    values[i][j] += pow(10, k-1)*(s[s.length()-k]-48);
                }
            }
            else {
                values[i][j] = -1;
                for (int k = 0; k < s.length()-1; k++){
                    if (s[k] == '+'){
                        continue;
                    }
                    else {
                        int x = s[k]-65;
                        int y = s[k+1]-49;
                        if (x == i && y == j){
                            values[i][j] = INT_MAX;
                        }
                        else {
                            graph[i][j].emplace_back(x, y);
                            k++;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 9; j++){
            if (graph[i][j].empty()){
                if (values[i][j] >= 1000000000 || values[i][j] < 0){
                    cout << "* ";
                }
                else {
                    cout << values[i][j] << " ";
                }
            }
            else {
                bool visited[10][9];
                for (int k = 0; k < 10; k++){
                    for (int l = 0; l < 9; l++){
                        visited[k][l] = false;
                    }
                }
                unsigned long long ans = dfs(i, j, visited);
                if (ans >= 1000000000 || ans < 0){
                    cout << "* ";
                }
                else {
                    cout << ans << " ";
                }
            }
        }
        cout << "\n";
    }
}