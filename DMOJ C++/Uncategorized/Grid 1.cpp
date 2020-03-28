#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

unsigned long long dp[1010][1010];
int main() {
    int h, w;
    unsigned long long m = 1000000000 + 7;
    cin >> h >> w;
    string graph[h];
    for (int i = 0; i < h; i++){
        cin >> graph[i];
    }
    dp[1][1] = 1;
    bool leftBlock = false, upBlock = false;
    for (int i = 1; i <= w; i++){
        if (leftBlock){
            dp[1][i] = 0;
        }
        else if (graph[0][i-1] != '#'){
            dp[1][i] = 1;
        }
        else {
            leftBlock = true;
        }
    }
    for (int i = 1; i <= h; i++){
        if (upBlock) {
            dp[i][1] = 0;
        }
        else if (graph[i-1][0] != '#') {
            dp[i][1] = 1;
        }
        else {
            upBlock = true;
        }
    }
    for (int i = 2; i <= h; i++){
        for (int j = 2; j <= w; j++){
            unsigned long long left = 0;
            unsigned long long up = 0;
            if (graph[i-1][j-2] != '#'){
                left = dp[i][j-1];
            }
            if (graph[i-2][j-1] != '#'){
                up = dp[i-1][j];
            }
            dp[i][j] = (left%m + up%m)%m;
        }
    }
    if (graph[0][0] == '#' || graph[h-1][w-1] == '#'){
        cout << 0;
    }
    else {
        cout << dp[h][w] % m;
    }
}