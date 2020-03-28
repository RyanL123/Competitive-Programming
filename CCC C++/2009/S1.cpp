#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;
    int cool = 0;
    int cubeA = ceil(cbrt(a)), cubeB = floor(cbrt(b));
    int sqrtA = ceil(sqrt(a)), sqrtB = floor(sqrt(b));
    for (int i = cubeA; i <= cubeB; i++){
        int leCube = pow(i, 3);
        if ((int)sqrt(leCube) - sqrt(leCube) == 0){
            cool++;
        }
    }
    cout << cool;
}
