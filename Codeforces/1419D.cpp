#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define srt(x) sort(x.begin(), x.end())
#define all(x) x.begin(), x.end()
#define inf 0x3f3f3f3f

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a[n+1], b[n+1];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    if (n%2==0) {
        int i = 0;
        for (int ptr = 0; ptr < n; i++, ptr+=2) {
            b[ptr] = a[i];
        }
        for (int ptr = n-1; ptr >= 0; i++, ptr-=2) {
            b[ptr] = a[i];
        }
        cout << n/2-1 << '\n';
        for (int j = 0; j < n; j++) cout << b[j] << ' ';
        cout << '\n';
    }
    else {
        int i = 0;
        for (int ptr = 1; ptr < n-1; i++, ptr+=2) {
            b[ptr] = a[i];
        }
        for (int ptr = n-1; ptr >= 0; i++, ptr-=2) {
            b[ptr] = a[i];
        }
        cout << n/2 << '\n';
        for (int j = 0; j < n; j++) cout << b[j] << ' ';
        cout << '\n';
    }
}