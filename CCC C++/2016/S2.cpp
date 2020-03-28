#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int problem, n, input, total = 0;

    cin >> problem >> n;

    int dmoj[n];

    int peg[n];

    for (int i = 0; i < n; i++){
        cin >> input;
        dmoj[i] = input;
    }
    for (int i = 0; i < n; i++){
        cin >> input;
        peg[i] = input;
    }

    sort(dmoj, dmoj+n);

    sort(peg, peg+n);

    if (problem == 1){
        for (int i = 0; i < n; i++){
            if (dmoj[i] > peg[i]){
                total += dmoj[i];
            }
            else{
                total += peg[i];
            }
        }
    }
    else {
        reverse(dmoj, dmoj+n);
        for (int i = 0; i < n; i++){
            if (dmoj[i] > peg[i]){
                total += dmoj[i];
            }
            else{
                total += peg[i];
            }
        }
    }

    cout << total << endl;
}