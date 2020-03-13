#include <bits/stdc++.h>

using namespace std;

long long a[100010];
long long b[100010];

int main() {
    long long int t, n, m = 998244353;
    cin >> n >> t;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        cin >> b[i];
    }
    long long lo = 0, hi = 10;
    while (lo < hi){
        long long mid = (lo+hi)/2;
        long long h = 0;
        long long count = 0;
        for (int i = 0; i < n; i++){
            if (a[i] > mid){
                long long terms = floor((a[i]-mid)/b[i])+1;
                long long lastTerm = a[i]-b[i]*(terms-1);
                long long sum = (terms*(a[i] + lastTerm))/2;
                h += sum%m;
                count += terms;
            }
        }
        if (count == t){
            cout << h%m << "\n";
            return 0;
        }
        else if (count > t) lo = mid+1;
        else hi = mid;
    }
}