#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define inf 0x3f3f3f3f

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    ll lo = 0, hi = 1e15;
    ll result = 0;
    while (lo <= hi){
        ll m = (lo+hi)/2;
        ll ans = floor(m/2)-floor(m/7);
        if (ans == t){
            result = m;
            break;
        }
        else if (ans > t){
            hi = m;
        }
        else {
            lo = m;
        }
    }
    while (true){
        if (floor((result+1)/2)-floor((result+1)/7) <= t) {
            result++;
        }
        else {
            break;
        }
    }
    cout << result;
}