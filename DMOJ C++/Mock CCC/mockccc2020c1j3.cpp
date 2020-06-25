#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    long double x, y;
    cin >> x >> y;
    long double ans = x*y/4;
    printf("%.2Lf\n", ans);
}