#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <tuple>

using namespace std;

int dp[2][1000010];

int main() {
    int n, t;
    cin >> n >> t;
    vector<tuple<pair<int, int>, pair<int, int>, pair<int, int>>> obj;
    for (int i = 0; i < n; i++) {
        pair<int, int> good;
        pair<int, int> avg;
        pair<int, int> poor;
        for (int j = 0; j < 3; j++) {
            int value, time;
            cin >> time >> value;
            if (j == 0) poor = make_pair(time, value);
            if (j == 1) avg = make_pair(time, value);
            if (j == 2) good = make_pair(time, value);
        }
        obj.push_back(make_tuple(poor, avg, good));
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= t; j++) {
            if (i % 2 == 0) {
                int takePoor = -INT_MAX;
                int takeAvg = -INT_MAX;
                int takeGood = -INT_MAX;
                if (get<0>(obj[i-1]).first <= j){
                    takePoor = dp[1][j-get<0>(obj[i-1]).first] + get<0>(obj[i-1]).second;
                }
                if (get<1>(obj[i-1]).first <= j){
                    takeAvg = dp[1][j-get<1>(obj[i-1]).first] + get<1>(obj[i-1]).second;
                }
                if (get<2>(obj[i-1]).first <= j){
                    takeGood = dp[1][j-get<2>(obj[i-1]).first] + get<2>(obj[i-1]).second;
                }
                int notTake = dp[1][j];
                dp[0][j] = max(max(takePoor, takeAvg), max(takeGood, notTake));
            }
            else {
                int takePoor = -INT_MAX;
                int takeAvg = -INT_MAX;
                int takeGood = -INT_MAX;
                if (get<0>(obj[i-1]).first <= j){
                    takePoor = dp[0][j-get<0>(obj[i-1]).first] + get<0>(obj[i-1]).second;
                }
                if (get<1>(obj[i-1]).first <= j){
                    takeAvg = dp[0][j-get<1>(obj[i-1]).first] + get<1>(obj[i-1]).second;
                }
                if (get<2>(obj[i-1]).first <= j){
                    takeGood = dp[0][j-get<2>(obj[i-1]).first] + get<2>(obj[i-1]).second;
                }
                int notTake = dp[0][j];
                dp[1][j] = max(max(takePoor, takeAvg), max(takeGood, notTake));
            }
        }
    }
    if (n%2 == 0){
        cout << dp[0][t];
    }
    else {
        cout << dp[1][t];
    }
}