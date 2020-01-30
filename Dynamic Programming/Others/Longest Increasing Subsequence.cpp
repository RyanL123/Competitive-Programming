#include <iostream>

using namespace std;

//TLE, use nlogn implementation
int main() {
    int n, longest = -1;
    cin >> n;
    int arr[n], dp[n];
    dp[0] = 1;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    // Longest Increasing Subsequence up until I elements
    for (int i = 0; i < n; i++){
        // LIS of 1 element is 1
        dp[i] = 1;
        for (int j = 0; j < i; j++){
            // Current value is smaller than last included element
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1){
                dp[i] = dp[j]+1;
            }
        }
    }
    for (int i = 0; i < n; i++){
        if (dp[i] > longest){
            longest = dp[i];
        }
    }
    cout << longest;
}
