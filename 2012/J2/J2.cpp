#include <iostream>

using namespace std;

int main(){
    int r1;
    int r2;
    int r3;
    int r4;

    cin >> r1 >> r2 >> r3 >> r4;

    if (r1 == r2 && r2 == r3 && r3 == r4){
        cout << "Fish At Constant Depth";
    }
    else if (r1 <= r2 && r2 <= r3 && r3 <= r4){
        cout << "Fish Rising";
    }
    else if (r1 > r2 && r2 > r3 && r3 > r4){
        cout << "Fish Diving";
    }
    else{
        cout << "No Fish";
    }
}
