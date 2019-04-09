#include <iostream>

using namespace std;


int main(){
    int n, a;
    cin >> n;
    int flowers[n][n];

    //takes grid input
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j ++){
            cin >> a;
            flowers[i][j] = a;
        }
    }

    //checks if the grid is in increasing order
    bool correct = true;
    while (true){
        for (int i = 0; i < n; i++){
            int smallest = 0;
            for (int j = 0; j < n; j++){
                if (flowers[i][j] >= smallest){
                    smallest = flowers[i][j];
                }
                else{
                    correct = false;
                    break;
                }
            }
            if (!correct){
                break;
            }
        }
        if (correct){
            break;
        }

        //rotates the grid 90 degrees

    }

    //prints out the grid
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << flowers[i][j] << " ";
        }
        cout << "\n";
    }
}
