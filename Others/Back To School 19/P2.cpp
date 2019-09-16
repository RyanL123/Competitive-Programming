#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main() {
    int x, y, h, v, t;
    scanf("%i%i%i%i%i", &x, &y, &h, &v, &t);
    int steps[x+h+10][y+v+10];
    queue<pair<int, int>> q;

    for (int i = 0; i <= x+h; i++){
        for (int j = 0; j <= y+v; j++){
            steps[i][j] = 99999999;
        }
    }
    steps[0][0] = 0;
    q.push(make_pair(0,0));

    while (!q.empty()){
        int x1 = q.front().first;
        int y1 = q.front().second;
        if (x1+1 <= x1+h && y1+2 <= y1+v && steps[x1+1][y1+2] > steps[x1][y1]+1){
            steps[x1+1][y1+2] = steps[x1][y1]+1;
            q.push(make_pair(x1+1, y1+2));
        }
        if (x1+2 <= x1+h && y1+1 <= y1+v && steps[x1+2][y1+1] > steps[x1][y1]+1){
            steps[x1+2][y1+1] = steps[x1][y1]+1;
            q.push(make_pair(x1+2, y1+1));
        }
        q.pop();
    }

    for (int i = x; i <= x+h; i++){
        for (int j = y; j <= y+v; j++){
            if (steps[i][j] < t){
                printf("YES");
                return 0;
            }
        }
    }
    printf("NO");

}