#include <iostream>
#include <queue>
#include <climits>

using namespace std;

int steps[1010][1010];
int main() {
    int r, c, t, startingC, startingR, endingC, endingR;
    cin >> r >> c;
    char graph[r][c];
    cin >> startingR >> startingC;
    cin >> endingR >> endingC;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin >> graph[i][j];
        }
    }
    for (int i = 0; i <= 1000; i++){
        for (int j = 0; j <= 1000; j++){
            steps[i][j] = INT_MAX;
        }
    }
    graph[endingR][endingC] = 'E';
    cin >> t;
    for (int i = 0; i < t; i++){
        int tR, tC;
        cin >> tR >> tC;
        graph[tR][tC] = 'T';
    }
    int shortestT = INT_MAX;
    if (graph[startingR][startingC] == 'T'){
        shortestT = 0;
    }
    queue<pair<int, int>> q;
    steps[startingR][startingC] = 0;
    q.push(make_pair(startingR, startingC));
    while (!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        if (row + 1 < r && steps[row][col] + 1 < steps[row+1][col] && graph[row+1][col] != 'X'){
            steps[row+1][col]  = steps[row][col] + 1;
            q.push(make_pair(row+1, col));
            if (graph[row+1][col] == 'T' && steps[row+1][col] < shortestT){
                shortestT = steps[row+1][col];
            }
        }
        if (row - 1 >= 0 && steps[row][col] + 1 < steps[row-1][col] && graph[row-1][col] != 'X'){
            steps[row-1][col] = steps[row][col] + 1;
            q.push(make_pair(row-1, col));
            if (graph[row-1][col] == 'T' && steps[row-1][col] < shortestT){
                shortestT = steps[row-1][col];
            }
        }
        if (col + 1 < c && steps[row][col] + 1 < steps[row][col+1] && graph[row][col+1] != 'X'){
            steps[row][col+1] = steps[row][col] + 1;
            q.push(make_pair(row, col+1));
            if (graph[row][col+1] == 'T' && steps[row][col+1] < shortestT){
                shortestT = steps[row][col+1];
            }
        }
        if (col - 1 >= 0 && steps[row][col] + 1 < steps[row][col-1] && graph[row][col-1] != 'X'){
            steps[row][col-1] = steps[row][col] + 1;
            q.push(make_pair(row, col-1));
            if (graph[row][col-1] == 'T' && steps[row][col-1] < shortestT){
                shortestT = steps[row][col-1];
            }
        }
    }
    if (steps[endingR][endingC] - shortestT > 0){
        cout << steps[endingR][endingC] - shortestT;
    }
    else {
        cout << 0;
    }

}
