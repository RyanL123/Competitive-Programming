#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main() {
    int mountain[10][10];
    for (int i = 0; i < 10; i++){
        unsigned long long height;
        scanf("%i", &height);
        mountain[i][0] = height / 1000000000 % 10;
        mountain[i][1] = height / 100000000 % 10;
        mountain[i][2] = height / 10000000 % 10;
        mountain[i][3] = height / 1000000 % 10;
        mountain[i][4] = height / 100000 % 10;
        mountain[i][5] = height / 10000 % 10;
        mountain[i][6] = height / 1000 % 10;
        mountain[i][7] = height / 100 % 10;
        mountain[i][8] = height / 10 % 10;
        mountain[i][9] = height % 10;
    }
    cout << " ";
}