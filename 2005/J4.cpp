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

    //simulates the walk
    int i = 0, j = 0, x, y;
    char lastDir = 'Z';
    while (true){
        if (steps == 0) break;
        //finds the starting square
        if (!room[i][j]){
            j++;
        }
        else{
            //records the current square as walked
            room[i][j] = !room[i][j];

            //if the square to the right has not been walked
            if (room[i][j+1] && (j+1) != column){
                j++;;
                lastDir = 'R';
            }
            //checks if the square below has been walked
            else if (room[i+1][j] && (i+1) != row){
                i++;
                lastDir = 'D';
            }
            //checks if the square to the left has been walked
            else if (room[i][j-1] && j != 0 && j+1){
                j--;
                lastDir = 'L';
            }
            //checks if the square above has been walked
            else if (room[i-1][j] && i != 0){
                i--;
                lastDir = 'U';
            }
            x = j;
            y = i;
            steps--;
        }
    }

    //outputs coordinates for the final square
    cout << x+1 << endl;
    cout << y+1 << endl;
}
