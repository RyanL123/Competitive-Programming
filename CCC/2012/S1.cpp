#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int j;
    cin >> j;
    if (j < 4){
        cout << 0;
        return 0;
    }
    else if (j == 4){
        cout << 1;
        return 0;
    }
    long long ans = 1;
    for (int i = 1; i <= 3; i++){
        ans*=j-i;
    }
    cout << ans/6;
}
