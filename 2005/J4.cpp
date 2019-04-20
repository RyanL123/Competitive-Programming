#include <iostream>

using namespace std;



int main(){

    int row, column, cornerL, cornerH, steps;

    cin >> column >> row >> cornerL >> cornerH >> steps;

    //2D boolean array to check visited squares/invalid squares
    bool room[row][column];

    //sets corners of the room to false
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            if ((j+1) <= cornerL || j >= (column-cornerL)){
                if (((i+1) <= cornerH) || i >= (row-cornerH)){
                    room[i][j] = false;
                }
                else {
                    room[i][j] = true;
                }
            }
            else {
                room[i][j] = true;
            }
        }
    }

    //walk simulation below

    int startingY;
    char dir = 'R';

    //finds the starting square
    for (int i = 0; i < column; i++){
        if (room[0][i]){
            startingY = i;
            break;
        }
    }

    int i = 0, j = startingY, x, y;

    //simulates the walk
    while (true){
        if (steps == 0) break;

        //records the current square as walked
        room[i][j] = false;

        if (!room[i-1][j] && !room[i+1][j] && !room[i][j+1] && !room[i][j-1]){
            break;
        }
        //keeps walking right until no longer possible
        if (dir == 'R'){
            //walk right
            if (room[i][j+1] && (j+1) != column){
                j++;
            }
            //walk down
            else if (room[i+1][j] && (i+1) != row) {
                i++;
            }
            else {
                dir = 'D';
                steps++;
            }
        }
        //keeps walking down until no longer possible
        else if (dir == 'D'){
            //walk down
            if (room[i+1][j] && (i+1) != row){
                i++;
            }
            //walk left
            else if (room[i][j-1] && j != 0 && j+1){
                j--;
            }
            else{
                dir = 'L';
                steps++;
            }

        }
        //keeps walking left until no longer possible
        else if (dir == 'L'){
            //walk left
            if (room[i][j-1] && j != 0 && j+1){
                j--;
            }
            //walk up
            else if (room[i-1][j] && i != 0){
                i--;
            }
            else{
                dir = 'U';
                steps++;
            }

        }
        else if (dir == 'U'){
            //walk up
            if (room[i-1][j] && i != 0){
                i--;
            }
            //walk right
            else if (room[i][j+1] && (j+1) != column){
                j++;
            }
            else{
                dir = 'R';
                steps++;
            }
        }
        x = j;
        y = i;
        steps--;
    }

    //outputs coordinates for the final square
    cout << x+1 << "\n";
    cout << y+1 << "\n";
}
