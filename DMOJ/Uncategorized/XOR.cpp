#include <iostream>

using namespace std;

int main() {
    int a,b,c;
    int d;
    cin >> a;
    for (int i = 0; i < a; i++){
        cin >> b >> c;
        d = b;
        for (int j = b+1; j < c+1; j++){
            d = d^j;
        }
        cout << d << endl;
    }
}