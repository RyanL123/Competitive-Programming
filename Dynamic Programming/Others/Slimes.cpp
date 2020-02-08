#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

pair<long long, long long> dp[410][410];

pair<long long, long long> solve(int start, int end, int slimes[410]){
    if (start > end){
        return make_pair(INT_MAX, INT_MAX);
    }
    if (dp[start][end].first != 0){
        return dp[start][end];
    }
    else if (start == end){
        return make_pair(slimes[start], 0);
    }
    else if (abs(start - end) == 1){
        return make_pair(slimes[start] + slimes[end], slimes[start] + slimes[end]);
    }
    long long size = LONG_LONG_MAX;
    long long cost = LONG_LONG_MAX;
    long long total = LONG_LONG_MAX;
    for (int i = start; i < end; i++){
        pair<long long, long long> val1 = solve(start, i, slimes);
        pair<long long, long long> val2 = solve(i+1, end, slimes);
        if (val1.first + val2.first + val1.second + val2.second < total){
            size = val1.first + val2.first;
            cost = val1.second + val2.second;
            total = cost + size;
        }
    }
    return dp[start][end] = make_pair(size, total);
}

int main() {
    int n;
    cin >> n;
    int slimes[n+1];
    for (int i = 1; i <= n; i++){
        cin >> slimes[i];
    }
    cout << solve(1, n, slimes).second;
}