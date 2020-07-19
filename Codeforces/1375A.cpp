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
    int t;
    cin >> t;
    while (t--) {
        int n, A = 0, B = 0;
        cin >> n;
        int a[n+1];
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (i%2) a[i] = abs(a[i]);
            else a[i] = -abs(a[i]);
        }
        for (int i = 1; i <= n; i++) cout << a[i] << ' ';
        cout << '\n';
    }
}