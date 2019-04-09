#include <iostream>
#include <math.h>

using namespace std;

/*
 * 
 */
int main() {
    int h;
    int m;
    int t = 1;
    cin >> h >> m;
    int a = -6*1 + h*1 + 2*1 + 1;
    
    bool withinTime = true;
    for (int i = 1; a > 0; i++){
        a = -6*pow(i, 4) + h*pow(i, 3) + 2*pow(i, 2) + i;
        if (i > m){
            withinTime = false;
            break;
        }
        t = i;
    }
    if (withinTime){
        cout << "The balloon first touches ground at hour: \n" ;
        cout << t;
    }
    else {
        cout << "The balloon does not touch ground in the given time.";
    }
    
}
