#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define srt(x) sort(x.begin(), x.end())
#define inf 0x3f3f3f3f

bool f(ll x, ll n, ll k){
    return x - x/n < k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        ll n, k;
        cin >> n >> k;
        ll lo = 0, hi = 1e11;
        while (hi - lo > 1){
            ll m = (lo+hi)/2;
            if (f(m, n, k)) lo = m;
            else hi = m;
        }
        for (ll i = lo; i <= hi; i++){
            if (i%n != 0 && i - floor(i/n) == k){
                cout << i << '\n';
                break;
            }
        }
    }
}