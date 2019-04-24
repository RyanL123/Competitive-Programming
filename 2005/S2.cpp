#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int c,r,a,b,x = 0, y = 0;
    cin >> c >> r;
    while (cin >> a >> b){
        if (a == 0 && b == 0){
            break;
        }
        if (x+a > c){
            x = c;
        }
        else if (x+a < 0){
            x = 0;
        }
        else{
            x += a;
        }
        if (y+b > r){
            y = r;
        }
        else if (y+b < 0){
            y = 0;
        }
        else{
            y += b;
        }
        printf("%i %i\n", x, y);
    }
}