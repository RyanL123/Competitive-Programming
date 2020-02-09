#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <utility>

using namespace std;

int main() {
    int a[5];
    int b[5];
    for (int i = 0; i < 5; i++){
        cin >> a[i];
    }
    for (int i = 0; i < 5; i++){
        cin >> b[i];
    }
    sort(a, a+5);
    sort(b, b+5);
    int maxA = a[4] + a[3] + a[2] + a[1];
    int maxB = b[4] + b[3] + b[2] + b[1];
    cout << max(maxA, maxB);
}
