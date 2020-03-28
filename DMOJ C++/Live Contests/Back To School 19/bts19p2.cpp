#include <iostream>
#include <cstdio>
#include <climits>

using namespace std;

int main() {
    int x, y, h, v, t;
    scanf("%i%i%i%i%i", &x, &y, &h, &v, &t);
    bool flag = false;
    for (int i = 1; i <= t; i++){
        int curX = i;
        int curY = 2*i;
        if (curX + 2*(t-1-i) >= x && curY + (t-1-i) >= y){
            flag = true;
        }
    }
    if (flag){
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}