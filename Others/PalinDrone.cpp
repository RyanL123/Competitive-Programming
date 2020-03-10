#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

unsigned long long m = 1000000000;
unsigned long long power(int n, unsigned long long exp){
    if (exp == 0){
        return 1;
    }
    if (exp%2 == 0){
        return power((int)pow(n, 2)%m, exp/2)%m;
    }
    return (n%m*power((int)pow(n, 2)%m, (exp-1)/2)%m)%m;
}

int main() {
    unsigned long long n;
    cin >> n;
    unsigned long long ans = 8;
    if (n == 1){
        cout << 8;
    }
    else {
        if (n%2==0){
            ans += power(10, n/2);
        }
        else {
            ans += power(10, floor(n/2));
        }
    }
    cout << ans%m;
}