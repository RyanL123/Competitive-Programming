#include <iostream>

using namespace std;

int main(){
    int n, a;

    cin >> n;

    int flowers[150][150] = {0};

    //takes grid input
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> a;
            flowers[i][j] = a;
        }
    }

    //grid is not rotated
    if (flowers[0][0] < flowers[0][1] && flowers[0][0] < flowers[1][0]){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cout << flowers[i][j] << " ";
            }
            cout << "\n";
        }
    }
    //grid is rotated 90 degrees
    else if (flowers[0][n-1] < flowers[1][n-1] && flowers[0][n-1] < flowers[0][n-2]){
        for (int i = n-1; i >= 0; i--){
            for (int j = 0; j < n; j++){
                cout << flowers[j][i] << " ";
            }
            cout << "\n";
        }
    }
    //grid is rotated 180 degrees
    else if (flowers[n-1][n-1] < flowers[n-2][n-1] && flowers[n-1][n-1] < flowers[n-1][n-2]){
        for (int i = n-1; i >= 0; i--){
            for (int j = n-1; j >= 0; j--){
                cout << flowers[i][j] << " ";
            }
            cout << "\n";
        }
    }
    //grid is rotated 270 degrees
    else if (flowers[n-1][0] < flowers[n-2][0] && flowers[n-1][0] < flowers[n-1][1]){
        for (int i = 0; i < n; i++){
            for (int j = n-1; j >= 0; j--){
                cout << flowers[j][i] << " ";
            }
            cout << "\n";
        }
    }
}
