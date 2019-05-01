#include <iostream>
#include <vector>
#include <cstdio>

#define first queue[0]
#define second queue[1]

using namespace std;

//determines if the adjacent square can be reached
bool hop(int x, int y, int x1, int y1, int n){
    if (x+x1 <= n && y+y1 <= n && x+x1 > 0 && y+y1 > 0){
        return true;
    }
    return false;
}

int main(){

    int n,trips,elevation;

    scanf("%i", &trips);

    for (int i = 0; i < trips; i++){
        scanf("%i", &n);

        //creates mountain grid with elevation
        int mountain[n+1][n+1];
        for (int j = 1; j <= n; j++){
            for (int k = 1; k <= n; k++){
                scanf("%i", &elevation);
                mountain[j][k] = elevation;
            }
        }

        //bfs

        //visited array to store visited nodes
        bool visited[n+1][n+1];
        for (int j = 0; j <= n; j++){
            for (int k = 0; k <= n; k++){
                visited[j][k] = false;
            }
        }

        //oxygen array to count the oxygen consumed at any node
        int oxygenLevel[n+1][n+1];
        for (int j = 0; j <= n; j++){
            for (int k = 0; k <= n; k++){
                oxygenLevel[j][k] = -1;
            }
        }
        oxygenLevel[1][1] = 0;

        //initializes (1,1) into queue and visited array
        vector<int>queue;
        visited[1][1] = true;
        queue.push_back(1);
        queue.push_back(1);
        int oxyCap = mountain[1][1];

        //checks where to move and records amount of oxygen it takes to get there
        while (!queue.empty()){
            //down
            if (hop(first, second, 1, 0, n) && !visited[first+1][second] && abs(mountain[first+1][second] - mountain[first][second]) <= 2){
                //if the elevation is above the initial elevation, add 1 to oxygen level, or else set is as the same oxygen level
                if (mountain[first+1][second] > oxyCap || mountain[first][second] > oxyCap){
                    oxygenLevel[first+1][second] = oxygenLevel[first][second]+1;
                }
                else{
                    oxygenLevel[first+1][second] = oxygenLevel[first][second];
                }
                visited[first+1][second] = true;
                queue.push_back(first+1);
                queue.push_back(second);
            }
            //left
            if (hop(first, second, 0, -1, n) && !visited[first][second-1] && abs(mountain[first][second-1] - mountain[first][second]) <= 2){
                if (mountain[first][second-1] > oxyCap || mountain[first][second] > oxyCap){
                    oxygenLevel[first][second-1] = oxygenLevel[first][second]+1;
                }
                else{
                    oxygenLevel[first][second-1] = oxygenLevel[first][second];
                }
                visited[first][second-1] = true;
                queue.push_back(first);
                queue.push_back(second-1);
            }
            //up
            if (hop(first, second, -1, 0, n) && !visited[first-1][second] && abs(mountain[first-1][second] - mountain[first][second]) <= 2){
                if (mountain[first-1][second] > oxyCap || mountain[first][second] > oxyCap){
                    oxygenLevel[first-1][second] = oxygenLevel[first][second]+1;
                }
                else{
                    oxygenLevel[first-1][second] = oxygenLevel[first][second];
                }
                visited[first-1][second] = true;
                queue.push_back(first-1);
                queue.push_back(second);
            }
            //right
            if (hop(first, second, 0, 1, n) && !visited[first][second+1] && abs(mountain[first][second+1] - mountain[first][second]) <= 2){
                if (mountain[first][second+1] > oxyCap || mountain[first][second] > oxyCap){
                    oxygenLevel[first][second+1] = oxygenLevel[first][second]+1;
                }
                else{
                    oxygenLevel[first][second+1] = oxygenLevel[first][second];
                }
                visited[first][second+1] = true;
                queue.push_back(first);
                queue.push_back(second+1);
            }
            queue.erase(queue.begin());
            queue.erase(queue.begin());
        }
        if (oxygenLevel[n][n] == -1){
            printf("CANNOT MAKE THE TRIP\n\n");
        }
        else{
            printf("%i\n\n", oxygenLevel[n][n]);
        }
    }
}
