#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef long long ll;
typedef unsigned long long ull;
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define inf INT_MAX

int diff[100010];
int prefixSum[100010];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int i, n, j;
    cin >> i >> n >> j;
    while (j--){
        int xi, xf, k;
        cin >> xi >> xf >> k;
        diff[xi] += k;
        diff[xf+1] -= k;
    }
    for (int k = 1; k <= i; k++){
        if (k == 1){
            prefixSum[k] = diff[k];
        }
        else {
            prefixSum[k] = diff[k] + prefixSum[k-1];
        }
    }
    int count = 0;
    for (int k = 1; k <= i; k++){
        if (prefixSum[k] < n){
            count++;
        }
    }
    cout << count;
}