#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int problem, n, input;

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

    for (int i = 0; i < n; i++){
        cout << dmoj[n];
    }

}