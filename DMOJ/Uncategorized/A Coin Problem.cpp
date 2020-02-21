#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;


int dp[10010];
int main() {
    int n, v, c, l;
    cin >> n >> v;
    int coins[n];
    vector<pair<int, int>> query;
    int answer[100010];
    for (int i = 0; i < n; i++){
        scanf("%i", &coins[i]);
    }
    for (int i = 0; i < v; i++){
        scanf("%i%i", &c, &l);
        query.emplace_back(make_pair(l, c));
    }
    for (int j = 0; j <= 10010; j++){
        dp[j] = INT_MAX;
    }
    dp[0] = 0;
    // Max coins
    for (int i = 1; i <= n; i++){
        // Total amount
        for (int j = 1; j < 10010; j++){
            if (coins[i-1] <= j){
                int useCoin = dp[j-coins[i-1]]+1;
                if (useCoin != INT_MAX && useCoin >= 0){
                    if (dp[j] < -1){
                        dp[j] = INT_MAX;
                    }
                    dp[j] = min(useCoin, dp[j]);
                    if (dp[j] == INT_MAX){
                        dp[j] = -1;
                    }
                }
            }
        }
        for (int j = 0; j < query.size(); j++){
            if (query[j].first == i){
                answer[j] = dp[query[j].second];
            }
        }
    }
    for (int i = 0; i < query.size(); i++){
        if (answer[i] == INT_MAX){
            printf("-1\n");
        }
        else {
            printf("%i\n", answer[i]);
        }
    }
}