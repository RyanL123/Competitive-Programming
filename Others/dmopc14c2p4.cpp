#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <utility>

using namespace std;

int main() {
    int n;
    cin >> n;
    int prefixSum[n];
    int trees[n];
    for (int i = 0; i < n; i++){
        if (i == 0){
            int a;
            scanf("%d", &a);
            trees[i] = a;
            prefixSum[0] = a;
        }
        else {
            int a;
            scanf("%d", &a);
            prefixSum[i] = prefixSum[i-1] + a;
            trees[i] = a;
        }
    }
    int q;
    cin >> q;
    while (q--){
        int a, b;
        scanf("%d%d", &a, &b);
        if (a == b){
            printf("%d\n", trees[a]);
        }
        else if (min(a, b) == 0){
            printf("%d\n", prefixSum[max(a,b)]);
        }
        else {
            printf("%d\n", prefixSum[max(a,b)] - prefixSum[min(a,b)-1]);
        }
    }
}
