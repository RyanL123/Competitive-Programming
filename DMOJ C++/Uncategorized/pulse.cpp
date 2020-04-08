#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n, s, t;
    cin >> n >> s >> t;
    int waves[n];
    for (int i = 0; i < n; i++){
        cin >> waves[i];
    }
    int count = 0;
    for (int i = 0; i < n; i++){
        if (waves[i]*2 <= t && waves[i]*2 >= s){
            count++;
        }
    }
    cout << count;
}