#include <iostream>

using namespace std;

int main() {
    int n,r,s,d;
    int highest = 0, highest2 = 0, index = 0, index2 = 0;
    string N;
    cin >> n;
    string pc[n];
    int stats[n];

    //takes input
    for (int i = 0; i < n; i++){
        cin >> N >> r >> s >> d;
        stats[i] = 2*r + 3*s + d;
        pc[i] = N;
    }

    if (n == 1){
        cout << N;
    }
    else {
        //finds highest rated
        for (int i = 0; i < n; i++){
            //finds highest
            if (stats[i] > highest){
                highest = stats[i];
                index = i;
            }
            //if tied, sets the lexicographically smaller number as the highest
            else if (stats[i] == highest){
                if (pc[i] < pc[index]){
                    index = i;
                }
            }
        }
        stats[index] = -1;

        //finds second highest rated
        for (int i = 0; i < n; i++){
            if (stats[i] > highest2){
                highest2 = stats[i];
                index2 = i;
            }
            //if tied, sets the lexicographically smaller number as the second highest
            else if (stats[i] == highest2){
                if (pc[i] < pc[index2]){
                    index2 = i;
                }
            }
        }
        cout << pc[index] << endl;
        cout << pc[index2] << endl;
    }
}