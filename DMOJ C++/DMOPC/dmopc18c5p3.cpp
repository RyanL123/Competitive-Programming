#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define inf 0x3f3f3f3f

int a[200005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll sum = 0, len = 0, mx = 0;
    for (int l = 0, r = 0; r < n; r++){
        sum += a[r];
        len++;
        while (sum >= m) {
            sum -= a[l];
            l++;
            len--;
        }
        mx = max(mx, len);
    }
    cout << mx;
}
