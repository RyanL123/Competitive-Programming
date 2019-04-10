#include <iostream>

using namespace std;


int main() {
    int n, a, rt;

    cin >> n;
    int flowers[n][n];

    //takes grid input
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a;
            flowers[i][j] = a;
        }
    }

    while (true) {
        bool br;


        //checks the grid top to bottom
        for (int i = 0; i < n; i++) {
            bool order = true;
            int lowest = 0;
            for (int j = 0; j < n; j++) {
                if (flowers[j][i] < lowest) {
                    order = false;
                    break;
                }
                lowest = flowers[j][i];
            }
            if (!order) {
                break;
            } else {
                rt = 90;
                br = true;
                break;
            }
        }

        if (br){
            break;
        }


        //checks the grid right to left
        for (int i = n; i > 0; i--) {
            bool order = true;
            int lowest = 0;
            for (int j = n; j > 0; j--) {
                if (flowers[i][j] < lowest) {
                    order = false;
                    break;
                }
                lowest = flowers[i][j];
            }
            if (!order) {
                break;
            } else {
                rt = 180;
                br = true;
                break;
            }
        }

        if (br){
            break;
        }

        //checks the grid bottom to top
        for (int i = n; i > 0; i--) {
            bool order = true;
            int lowest = 0;
            for (int j = n; j > 0; j--) {
                if (flowers[j][i] < lowest) {
                    order = false;
                    break;
                }
                lowest = flowers[j][i];
            }
            if (!order) {
                break;
            } else {
                rt = 270;
                br = true;
                break;
            }
        }

        if (br){
            break;
        }

        //checks the grid left to right
        for (int i = 0; i < n; i++) {
            bool order = true;
            int lowest = 0;

            for (int j = 0; j < n; j++) {
                //checks to see if the grid is in order
                if (flowers[i][j] < lowest) {
                    order = false;
                    break;
                }
                lowest = flowers[i][j];
            }
            //if not in order, break and move on to the next loop
            if (!order) {
                break;
            }
                //if in order, set the rotation to 0 and break
            else {
                rt = 360;
                br = true;
                break;
            }
        }

        if (br){
            break;
        }

    }

    cout << rt << endl;
    //prints out the grid
//    for (int i = 0; i < n; i++){
//        for (int j = 0; j < n; j++){
//            cout << flowers[i][j] << " ";
//        }
//        cout << "\n";
//    }
}

