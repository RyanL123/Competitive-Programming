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

        //initialize visited array, steps array and sets starting node to 0
        char visited[w][l];
        int steps[w][l];
        memset(steps, -1, sizeof(steps));

        for (int j = 0; j < w; j++){
            for (int k = 0; k < l; k++){
                cin >> room;
                visited[j][k] = room;
                if (room == 'C'){
                    queue.push_back(j);
                    queue.push_back(k);
                    steps[j][k] = 0;
                }
                else if (room == 'W'){
                    tX = k;
                    tY = j;
                }
            }
        }

        //bfs

        //moves in every direction possible until target is not -1

        while (!queue.empty()){
            //tries to move in all 4 directions

            //up
            if (first-1 >= 0 && visited[first-1][second] != 'X' && steps[first-1][second] == -1){
                steps[first-1][second] = steps[first][second]+1;
                queue.push_back(first-1);
                queue.push_back(second);
            }
            //left
            if (second-1 >= 0 && visited[first][second-1] != 'X' && steps[first][second-1] == -1){
                steps[first][second-1] = steps[first][second]+1;
                queue.push_back(first);
                queue.push_back(second-1);
            }
            //down
            if (first+1 < w && visited[first+1][second] != 'X' && steps[first+1][second] == -1){
                steps[first+1][second] = steps[first][second]+1;
                queue.push_back(first+1);
                queue.push_back(second);
            }
            //right
            if (second+1 < l && visited[first][second+1] != 'X' && steps[first][second+1] == -1){
                steps[first][second+1] = steps[first][second]+1;
                queue.push_back(first);
                queue.push_back(second+1);
            }

            queue.erase(queue.begin());
            queue.erase(queue.begin());

        }

        if (steps[tY][tX] == -1 || steps[tY][tX] >= 60){
            printf("#notworth\n");
        }
        else{
            printf("%i\n", steps[tY][tX]);
        }
    }
}