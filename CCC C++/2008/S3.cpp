#include <iostream>
#include <queue>

using namespace std;

int main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int r, c;
        cin >> r >> c;
        char map[21][21];
        int steps[21][21];

        //initialize visited array
        for (int j = 0; j < 21; j++){
            for (int k = 0; k < 21; k++){
                steps[j][k] = 99;
            }
        }

        char sign;
        //initialize map of city
        for (int j = 0; j < r; j++){
            for (int k = 0; k < c; k++){
                cin >> sign;
                map[j][k] = sign;
            }
        }

        //bfs
        queue<pair<int, int>> q;
        steps[0][0] = 0;
        q.push(make_pair(0,0));

        while (!q.empty()){
            int first = q.front().first;
            int second = q.front().second;
            q.pop();
            int currentStep = steps[first][second];
            if (map[first][second] == '+'){
                if (first + 1 <= r){
                    if (map[first+1][second] != '*' && steps[first+1][second] > currentStep + 1){
                        q.push(make_pair(first+1,second));
                        steps[first+1][second] = currentStep + 1;
                    }
                }
                if (first - 1 >= 0){
                    if (map[first-1][second] != '*' && steps[first-1][second] > currentStep + 1){
                        q.push(make_pair(first-1,second));
                        steps[first-1][second] = currentStep + 1;
                    }
                }
                if (second + 1 <= c){
                    if (map[first][second+1] != '*' && steps[first][second+1] > currentStep + 1){
                        q.push(make_pair(first, second+1));
                        steps[first][second+1] = currentStep + 1;
                    }
                }
                if (second - 1 >= 0){
                    if (map[first][second-1] != '*' && steps[first][second-1] > currentStep + 1){
                        q.push(make_pair(first, second-1));
                        steps[first][second-1] = currentStep + 1;
                    }
                }
            }
            else if (map[first][second] == '|'){
                if (first + 1 <= r){
                    if (map[first+1][second] != '*' && steps[first+1][second] > currentStep + 1){
                        q.push(make_pair(first+1,second));
                        steps[first+1][second] = currentStep + 1;
                    }
                }
                if (first - 1 >= 0){
                    if (map[first-1][second] != '*' && steps[first-1][second] > currentStep + 1){
                        q.push(make_pair(first-1,second));
                        steps[first-1][second] = currentStep + 1;
                    }
                }
            }
            else if (map[first][second] == '-'){
                if (second + 1 <= c){
                    if (map[first][second+1] != '*' && steps[first][second+1] > currentStep + 1){
                        q.push(make_pair(first, second+1));
                        steps[first][second+1] = currentStep + 1;
                    }
                }
                if (second - 1 >= 0){
                    if (map[first][second-1] != '*' && steps[first][second-1] > currentStep + 1){
                        q.push(make_pair(first, second-1));
                        steps[first][second-1] = currentStep + 1;
                    }
                }
            }
        }
        if (steps[r-1][c-1] == 99){
            cout << -1 << endl;
        }
        else{
            cout << steps[r-1][c-1]+1 << endl;
        }
    }
}