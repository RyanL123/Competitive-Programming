#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

double dp[3010][3010];
int main() {
    int n;
    cin >> n;
    double coins[n+1];
    for (int i = 1; i <= n; i++){
        cin >> coins[i];
    }
    dp[1][0] = coins[1];
    for (int i = 1; i < 3010; i++){
        for (int j = 0; j < 3010; j++){

        }
    }
}
