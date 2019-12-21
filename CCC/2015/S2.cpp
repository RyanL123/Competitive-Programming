#include <iostream>

using namespace std;
int size[1000001];
int main() {
    //gets input
    int j,a,max = 0;
    char jersey;
    cin >> j >> a;

    //gets every jersey size and stores it as an int
    for (int i = 1; i < j+1; i++){
        cin >> jersey;
        //switches size to integer
        if (jersey == 'L'){
            size[i] = 2;
        }
        else if (jersey == 'M'){
            size[i] = 1;
        }
        else{
            size[i] = 0;
        }
    }

    //if a jersey matches a player, immediately gives it to that player
    int jerseySize, athlete;

    for (int i = 0; i < a; i++){
        cin >> jersey >> athlete;

        //switches size to integer
        if (jersey == 'L'){
            jerseySize = 2;
        }
        else if (jersey == 'M'){
            jerseySize = 1;
        }
        else{
            jerseySize = 0;
        }
        if (size[athlete] >= jerseySize && athlete <= j && athlete >= 1) {
            max++;
            size[athlete] = -1;
        }
    }
    cout << max;
}