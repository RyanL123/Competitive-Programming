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

int N, M;
vector<pair<ll, ll>> interval;
bool place(ll d){
    int placed = 0;
    ll pos = -1e18;
    for (pair<ll, ll> v : interval){
        while (max(pos + d, v.first) <= v.second){
            placed++;
            pos = max(pos + d, v.first) ;
        }
    }
    return placed >= N;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < M; i++){
        ll a, b;
        cin >> a >> b;
        interval.pb(mp(a,b));
    }
    sort(interval.begin(), interval.end());
    ll l = 0, r = 1e18;
    ll ans = -1;
    while (l <= r){
        ll m = (l+r)/2;
        if (place(m)){
            ans = m;
            l = m+1;
        }
        else r = m-1;
    }
    cout << ans << "\n";
}
