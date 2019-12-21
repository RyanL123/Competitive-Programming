#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int n;
    char input;
    scanf("%i", &n);
    int steps[n+10][n+10];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> input;
            if (input != '.'){
                steps[i][j] = -1;
            }
            else {
                steps[i][j] = 9999;
            }
        }
    }
    queue<pair<int, int>> q;
    vector<char> moves[n+10][n+10];
    q.push(make_pair(1,1));
    steps[1][1] = 0;
    while (!q.empty()){
        int first = q.front().first;
        int second = q.front().second;
        //down
        if (first < n && steps[first+1][second] > steps[first][second]+1){
            steps[first+1][second] = steps[first][second]+1;
            copy(moves[first][second].begin(), moves[first][second].end(), back_inserter(moves[first+1][second]));
//            moves[first+1][second] = moves[first][second];
            moves[first+1][second].push_back('D');
            q.push(make_pair(first+1, second));
        }
        //left
        if (second > 1 && steps[first][second-1] > steps[first][second]+1){
            steps[first][second-1] = steps[first][second]+1;
            copy(moves[first][second].begin(), moves[first][second].end(), back_inserter(moves[first][second-1]));
//            moves[first][second-1] = moves[first][second];
            moves[first][second-1].push_back('L');
            q.push(make_pair(first, second-1));
        }
        //right
        if(second < n && steps[first][second+1] > steps[first][second]+1){
            steps[first][second+1] = steps[first][second]+1;
            copy(moves[first][second].begin(), moves[first][second].end(), back_inserter(moves[first][second+1]));
//            moves[first][second+1] = moves[first][second];
            moves[first][second+1].push_back('R');
            q.push(make_pair(first, second+1));
        }
        q.pop();
    }
    if (n == 1){
        printf("0");
    }
    else if (moves[n][n].empty()){
        printf("-1");
    }
    else{
        int D = 0, L = 0, R = 0;
        for (int i = 0; i < moves[n][n].size(); i++){
            if (moves[n][n][i] == 'D'){
                D++;
            }
            else if (moves[n][n][i] == 'L'){
                L++;
            }
            else if (moves[n][n][i] == 'R'){
                R++;
            }
        }
        printf("%i", D*D+L*L+R*R);
    }
}