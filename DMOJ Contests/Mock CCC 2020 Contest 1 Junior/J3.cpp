#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

int main() {
    unsigned long long x, y;
    cin >> x >> y;
    unsigned long long area = x*y;
    if (x % 4 == 0 || y % 4 == 0){
        cout << (x*y)/4 << ".00" << endl;
    }
    else if (x % 2 == 0 && y % 2 == 0){
        cout << (x*y)/4 << ".00" << endl;
    }
    else if (x % 2 == 0 || y % 2 == 0){
        cout << (x*y)/4 << ".50" << endl;
    }
    else if ((double)x / 4 - floor(x/4) == 0.25 && (double)y / 4 - floor(y/4) == 0.25){
        cout << (x*y)/4 << ".25" << endl;
    }
    else {
        cout << (x*y)/4 << ".75" << endl;
    }
}