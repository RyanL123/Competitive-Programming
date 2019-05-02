#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#define first queue[0]
#define second queue[1]

using namespace std;

int main() {
    int t,l,w, tX, tY, cX, cY;
    char room;
    scanf("%i",&t);

    for (int i = 0; i < t; i++){
        scanf("%i%i", &l, &w);

        vector<int>queue;

        //initialize visited array and steps array
        char visited[w][l];
        int steps[w][l];
        for (int j = 0; j < w; j++){
            for (int k = 0; k < l; k++){
                cin >> room;
                visited[j][k] = room;
                if (room == 'C'){
                    queue.push_back(j);
                    queue.push_back(k);
                    cX = k;
                    cY = j;
                }
                else if (room == 'W'){
                    tX = k;
                    tY = j;
                }
            }
        }

        for (int j = 0; j < w; j++){
            for (int k = 0; k < l; k++){
                steps[j][k] = 5001;
            }
        }

//        memset(steps, 5001, sizeof(steps));
        steps[cY][cX] = 0;

        //bfs

        while (!queue.empty()){

            if (steps[tY][tX] != 5001){
                    break;
            }
            //tries to move in all 4 directions

            //down
            if (visited[first-1][second] != 'X' && steps[first-1][second] == -1 && first-1 < w && first-1 >= 0){
                steps[first-1][second] = steps[first][second]+1;
                queue.push_back(first-1);
                queue.push_back(second);
            }
            //left
            if (visited[first][second-1] != 'X' && steps[first][second-1] > steps[first][second] && second-1 < l && second-1 >= 0){
                steps[first][second-1] = steps[first][second]+1;
                queue.push_back(first);
                queue.push_back(second-1);
            }
            //up
            if (visited[first+1][second] != 'X' && steps[first+1][second] > steps[first][second] && first+1 < w && first+1 >= 0){
                steps[first+1][second] = steps[first][second]+1;
                queue.push_back(first+1);
                queue.push_back(second);
            }
            //right
            if (visited[first][second+1] != 'X' && steps[first][second+1] > steps[first][second] && second+1 < l && second+1 >= 0){
                steps[first][second+1] = steps[first][second]+1;
                queue.push_back(first);
                queue.push_back(second+1);
            }

            queue.erase(queue.begin());
            queue.erase(queue.begin());

        }

        if (steps[tY][tX] < 60){
            printf("%i\n", steps[tY][tX]);
        }
        else{
            printf("#notworth\n");
        }
    }
}