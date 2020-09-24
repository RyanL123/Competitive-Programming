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
        int n;
        cin >> n;
        ll a[n+1];
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a+n);
        ll x = a[0]*a[1]*a[n-1]*a[n-2]*a[n-3];
        ll y = a[0]*a[1]*a[2]*a[3]*a[n-1];
        ll z = a[n-1]*a[n-2]*a[n-3]*a[n-4]*a[n-5];
        cout << max(x, max(y, z)) << '\n';
    }
}