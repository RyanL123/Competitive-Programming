#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <utility>
#include <numeric>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int even = accumulate(arr, arr+n, 0)/n;
    int count = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] != even) {
            count++;
        }
    }
    cout << count;
}
