#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Whether a winning position can be obtained with n stones left when it's
bool dp[100010];
int main() {
    int n, k;
    cin >> n >> k;
    int stones[n];
    for (int i = 0; i < n; i++) {
        cin >> stones[i];
    }
    dp[0] = false;
    // K stones left
    for (int i = 1; i <= k; i++){
        // Using j'th stone
        for (int j = 0; j < n; j++){
            if (dp[i]){
                break;
            }
            if (stones[j] == i){
                dp[i] = true;
                break;
            }
            // Can players get to a winning position?
            else if (stones[j] < i){
                if (dp[i-stones[j]]){
                    dp[i] = false;
                }
                else if (!dp[i-stones[j]]){
                    dp[i] = true;
                    break;
                }
            }
            else continue;
        }
    }
    if (dp[k]){
        cout << "First";
    }
    else {
        cout << "Second";
    }
}
