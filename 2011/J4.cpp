#include <iostream>
#include <cstdio>

using namespace std;

int main(){

    int unit;
    char dir = 'Z';

    //initializes drill

    bool drill[501][501] {false};
    drill[0][250] = true;
    drill[1][250] = true;
    drill[2][250] = true;
    drill[2][251] = true;
    drill[2][252] = true;
    drill[2][253] = true;
    drill[3][253] = true;
    drill[4][253] = true;
    drill[4][254] = true;
    drill[4][255] = true;
    drill[3][255] = true;
    drill[2][255] = true;
    drill[2][256] = true;
    drill[2][257] = true;
    drill[3][257] = true;
    drill[4][257] = true;
    drill[5][257] = true;
    drill[6][257] = true;
    drill[6][256] = true;
    drill[6][255] = true;
    drill[6][254] = true;
    drill[6][253] = true;
    drill[6][252] = true;
    drill[6][251] = true;
    drill[6][250] = true;
    drill[6][249] = true;
    drill[5][249] = true;
    drill[4][249] = true;

    int x = -1, y = -5;
    bool danger = false;

    while (true){
        if (dir == 'q'){
            break;
        }
        cin >> dir >> unit;

        //drill left
        if (dir == 'l'){

            //simulates the drill step by step and checks for self intersection
            for (int i = 0; i < unit; i++){
                x--;
                if (drill[abs(y+1)][x+250]){
                    danger = true;
                }
                drill[abs(y+1)][x+250] = true;
            }

            //prints the ending point
            printf("%i %i ", x, y);

            //if there was a self intersection
            if (danger){
                printf("DANGER");
                break;
            }

            //if there wasn't a self intersection
            else{
                printf("safe\n");
                drill[abs(y+1)][x+250] = true;
            }
        }

        //drill right
        else if (dir == 'r'){
            for (int i = 0; i < unit; i++){
                x++;
                if (drill[abs(y+1)][x+250]){
                    danger = true;
                }
                drill[abs(y+1)][x+250] = true;
            }
            printf("%i %i ", x, y);
            if (danger){
                printf("DANGER");
                break;
            }
            else{
                printf("safe\n");
                drill[abs(y+1)][x+250] = true;
            }
        }

        //drill down
        else if (dir == 'd'){
            for (int i = 0; i < unit; i++){
                y--;
                if (drill[abs(y+1)][x+250]){
                    danger = true;
                }
                drill[abs(y+1)][x+250] = true;
            }
            printf("%i %i ", x, y);
            if (danger){
                printf("DANGER");
                break;
            }
            else{
                printf("safe\n");
                drill[abs(y+1)][x+250] = true;
            }
        }

        //drill up
        else if (dir == 'u'){
            for (int i = 0; i < unit; i++){
                y++;
                if (drill[abs(y+1)][x+250]){
                    danger = true;
                }
                drill[abs(y+1)][x+250] = true;
            }
            printf("%i %i ", x, y);
            if (danger){
                printf("DANGER");
                break;
            }
            else{
                printf("safe\n");
                drill[abs(y+1)][x+250] = true;
            }
        }
    }
}
