#include <iostream>

using namespace std;

int main(){
    int row, column, r2, c2, steps;

    cin >> column >> row >> c2 >> r2 >> steps;

    //2D boolean array to check visited squares/invalid squares
    bool room[row][column];

    //sets corners of the room to false
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            if ((i+1) <= r2 || (i+1) > row-r2 || (j+1) <= c2 || (j+1) > column-c2){
                room[i][j] = false;
            }
            else {
                room[i][j] = true;
            }
        }
    }
}
