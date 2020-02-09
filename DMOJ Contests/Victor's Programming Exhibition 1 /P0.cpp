#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <utility>

using namespace std;

int main() {
    int n, x;
    cin >> x >> n;
    if (x%n == 0){
        cout << x/n << " " << 0;
    }
    else {
        cout << (x-x%n)/n << " " << x%n;
    }
}
