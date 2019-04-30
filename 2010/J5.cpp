#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    //input
    int x,y,x2,y2;
    scanf("%i %i",&x,&y);
    scanf("%i %i",&x2,&y2);

    //initializes visited array
    int visited[9][9] {0};
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            visited[i][j] = 999;
        }
    }
    visited[x][y] = 0;

    //bfs

    vector<int> queue;

    //adds initial node into the queue
    queue.push_back(x);
    queue.push_back(y);


    //keep moving until target is found, increments steps 2D array along the way
    while (true){
        //found targeted square
        if (queue[0] == x2 && queue[1] == y2){
            printf("%i",visited[queue[0]][queue[1]]);
            break;
        }
        //add all available children nodes of the parent node and mark them as visited
        //top right
        if (visited[queue[0]+1][queue[1]+2] > visited[queue[0]][queue[1]]&& queue[0]+1 <= 8 && queue[1]+2 <= 8 && queue[0]+1 > 0 && queue[1]+2 > 0){
            visited[queue[0]+1][queue[1]+2] = visited[queue[0]][queue[1]]+1;
            queue.push_back(queue[0]+1);
            queue.push_back(queue[1]+2);
        }
        //right top
        if (visited[queue[0]+2][queue[1]+1] > visited[queue[0]][queue[1]] && queue[0]+2 <= 8 && queue[1]+1 <= 8 && queue[0]+2 > 0 && queue[1]+1 > 0){
            visited[queue[0]+2][queue[1]+1] = visited[queue[0]][queue[1]]+1;
            queue.push_back(queue[0]+2);
            queue.push_back(queue[1]+1);
        }
        //right bottom
        if (visited[queue[0]+2][queue[1]-1] > visited[queue[0]][queue[1]] && queue[0]+2 <= 8 && queue[1]-1 <= 8 && queue[0]+2 > 0 && queue[1]-1 > 0){
            visited[queue[0]+2][queue[1]-1] = visited[queue[0]][queue[1]]+1;
            queue.push_back(queue[0]+2);
            queue.push_back(queue[1]-1);
        }
        //bottom right
        if (visited[queue[0]+1][queue[1]-2] > visited[queue[0]][queue[1]] && queue[0]+1 <= 8 && queue[1]-2 <= 8 && queue[0]+1 > 0 && queue[1]-2 > 0){
            visited[queue[0]+1][queue[1]-2] = visited[queue[0]][queue[1]]+1;
            queue.push_back(queue[0]+1);
            queue.push_back(queue[1]-2);
        }
        //bottom left
        if (visited[queue[0]-1][queue[1]-2] > visited[queue[0]][queue[1]] && queue[0]-1 <= 8 && queue[1]-2 <= 8 && queue[0]-1 > 0 && queue[1]-2 > 0){
            visited[queue[0]-1][queue[1]-2] = visited[queue[0]][queue[1]]+1;
            queue.push_back(queue[0]-1);
            queue.push_back(queue[1]-2);
        }
        //left bottom
        if (visited[queue[0]-2][queue[1]-1] > visited[queue[0]][queue[1]] && queue[0]-2 < 8 && queue[1]-1 < 8 && queue[0]-2 > 0 && queue[1]-1 > 0){
            visited[queue[0]-2][queue[1]-1] = visited[queue[0]][queue[1]]+1;
            queue.push_back(queue[0]-2);
            queue.push_back(queue[1]-1);
        }
        //left top
        if (visited[queue[0]-2][queue[1]+1] > visited[queue[0]][queue[1]] && queue[0]-2 < 8 && queue[1]+1 < 8 && queue[0]-2 > 0 && queue[1]+1 > 0){
            visited[queue[0]-2][queue[1]+1] = visited[queue[0]][queue[1]]+1;
            queue.push_back(queue[0]-2);
            queue.push_back(queue[1]+1);
        }
        //top left
        if (visited[queue[0]-1][queue[1]+2] > visited[queue[0]][queue[1]] && queue[0]-1 < 8 && queue[1]+2 < 8 && queue[0]-1 > 0 && queue[1]+2 > 0){
            visited[queue[0]-1][queue[1]+2] = visited[queue[0]][queue[1]]+1;
            queue.push_back(queue[0]-1);
            queue.push_back(queue[1]+2);
        }

        //erase the current node
        queue.erase(queue.begin());
        queue.erase(queue.begin());
    }
}